#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility> // For pair
#include <numeric> // Not strictly needed here, but good to include if using related functions

using namespace std;

// Define MOD constant for modulo arithmetic
long long MOD = 1e9 + 7;

// Define Cell as pair<int, int> representing coordinates (x, y)
using Cell = pair<int, int>;

// Custom hash function for pair<int, int> (Cell) to use with unordered containers
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        // Combine hashes using a method similar to Boost's hash_combine
        // to reduce collisions. The magic number is arbitrary but common.
        size_t seed = 0;
        seed ^= h1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= h2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        return seed;
    }
};

// Type aliases for clarity
using CandidateSet = vector<Cell>; // Represents the possible cells for p_{2i}
// Use unordered_map for potentially faster lookups than std::map
using AssignmentMap = unordered_map<int, Cell>; // Map index i -> chosen cell p_2i

// Global variables for backtracking state within components
vector<CandidateSet> Cprime;                                // Stores candidate cells for each index i after initial filtering and simplification
vector<int> component_nodes;                                // Stores nodes (indices i) of the current component being processed by backtracking
AssignmentMap current_assignment;                           // Stores the current assignment of cells to indices during backtracking
vector<vector<int>> adj;                                    // Adjacency list for the component graph G_aux, connecting indices with shared candidates
unordered_set<Cell, pair_hash> assigned_cells_in_component; // Set to efficiently check if a cell is already assigned within the current component during backtracking

/**
 * Recursive function to perform backtracking search within a connected component.
 * Counts the number of valid ways to assign cells to indices p_{2i} such that all assigned cells are distinct.
 * @param node_list_idx The index within `component_nodes` currently being processed.
 * @return The number of valid partial assignments extending the current state.
 */
long long backtrack_component(int node_list_idx)
{
    // Base case: If all nodes in the component have been assigned a cell
    if (node_list_idx == component_nodes.size())
    {
        return 1; // Found one valid assignment for this component
    }

    int u = component_nodes[node_list_idx]; // Current node (index i) to assign
    long long count = 0;                    // Counter for valid ways for the rest of the component

    // Iterate through candidate cells for node u
    for (const auto &cell_choice : Cprime[u])
    {
        // Check if this cell choice conflicts with any previously assigned cell in this component
        // Use the dedicated set `assigned_cells_in_component` for an efficient check O(1) average time.
        if (assigned_cells_in_component.find(cell_choice) == assigned_cells_in_component.end())
        {
            // No conflict, proceed with this choice
            current_assignment[u] = cell_choice;             // Assign cell_choice to node u
            assigned_cells_in_component.insert(cell_choice); // Add cell to the set of assigned cells for quick conflict checking

            // Recursively call for the next node in the component list
            count = (count + backtrack_component(node_list_idx + 1)) % MOD;

            // Backtrack: Undo the assignment and remove the cell from the assigned set
            assigned_cells_in_component.erase(cell_choice);
            current_assignment.erase(u);
        }
    }
    return count; // Return total ways found starting from this state
}

int main()
{
    // Fast I/O settings
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        int n, m, k; // Grid dimensions and path parameter k
        cin >> n >> m >> k;

        vector<Cell> p_odd(k + 1);                // Stores the given odd-indexed path cells p_1, p_3, ..., p_{2k+1}
        unordered_set<Cell, pair_hash> P_odd_set; // Set for quick O(1) average time check if a cell is in p_odd
        for (int i = 0; i <= k; ++i)
        {
            cin >> p_odd[i].first >> p_odd[i].second;
            P_odd_set.insert(p_odd[i]);
        }

        // Initialize candidate sets Cprime for indices 1 to k
        Cprime.assign(k + 1, CandidateSet());
        bool possible = true; // Flag to track if a valid path restoration is possible

        // Step 1: Generate initial candidate sets for each p_{2i} and filter based on P_odd
        for (int i = 1; i <= k; ++i)
        {
            Cell p1 = p_odd[i - 1]; // p_{2i-1}
            Cell p3 = p_odd[i];     // p_{2i+1}
            // Calculate Manhattan distance between p_{2i-1} and p_{2i+1}
            int dist = abs(p1.first - p3.first) + abs(p1.second - p3.second);

            // A valid intermediate cell p_{2i} exists only if the Manhattan distance is exactly 2
            if (dist != 2)
            {
                possible = false;
                break;
            }

            // Find potential candidates for p_{2i} based on the relative positions of p_{2i-1} and p_{2i+1}
            vector<Cell> candidates;
            if (p1.first == p3.first)
            { // Co-linear horizontally (same row)
                candidates.push_back({p1.first, (p1.second + p3.second) / 2});
            }
            else if (p1.second == p3.second)
            { // Co-linear vertically (same column)
                candidates.push_back({(p1.first + p3.first) / 2, p1.second});
            }
            else
            { // Diagonal relationship
                // The two candidates are the other two corners of the 2x2 square
                candidates.push_back({p1.first, p3.second});
                candidates.push_back({p3.first, p1.second});
            }

            // Filter candidates:
            // 1. Must not be one of the given odd-indexed cells
            // 2. Must be within grid boundaries
            for (const auto &cand : candidates)
            {
                if (P_odd_set.find(cand) == P_odd_set.end())
                {
                    if (cand.first >= 1 && cand.first <= n && cand.second >= 1 && cand.second <= m)
                    {
                        Cprime[i].push_back(cand);
                    }
                }
            }

            // If no valid candidates remain after filtering, the path is impossible
            if (Cprime[i].empty())
            {
                possible = false;
                break;
            }
        }

        // If path impossible detected early
        if (!possible)
        {
            cout << 0 << "\n";
            continue;
        }

        // Step 2: Simplification phase
        // Use constraint propagation: if a node i has only one candidate cell, this choice is forced.
        // This forced choice might restrict options for other nodes connected via shared candidates.
        vector<int> q;                                               // Queue for nodes with a single candidate (forced choice)
        vector<int> Cprime_size(k + 1);                              // Track candidate set sizes dynamically during simplification
        unordered_map<Cell, vector<int>, pair_hash> cell_to_indices; // Map cell -> list of indices i where it's a candidate

        vector<bool> is_forced(k + 1, false);   // Tracks if node i's choice is forced
        unordered_map<int, Cell> forced_choice; // Stores the forced cell for index i

        // Initialize queue and cell_to_indices map based on current Cprime state
        for (int i = 1; i <= k; ++i)
        {
            Cprime_size[i] = Cprime[i].size();
            if (Cprime_size[i] == 1)
            {
                if (!is_forced[i])
                { // Check if not already marked forced by propagation
                    q.push_back(i);
                    is_forced[i] = true;
                }
            }
            for (const auto &cell : Cprime[i])
            {
                cell_to_indices[cell].push_back(i);
            }
        }

        int head = 0;                               // Queue head index for BFS-like processing
        unordered_set<Cell, pair_hash> fixed_cells; // Set of cells assigned via forcing process

        // Process forced choices and propagate constraints
        while (head < q.size())
        {
            int u = q[head++]; // Get node with a forced choice

            // Check if Cprime[u] has candidates left. Use tracked size.
            if (Cprime_size[u] == 0)
            {
                possible = false;
                break; // Became empty due to propagation, impossible
            }
            // Should have exactly one candidate. Get it.
            if (Cprime[u].empty())
            { // Robustness check
                possible = false;
                break;
            }
            Cell c = Cprime[u][0]; // The single remaining candidate cell

            // Check for conflict: cell c is already forced for *another* node.
            if (fixed_cells.count(c))
            {
                possible = false;
                break;
            }
            fixed_cells.insert(c); // Mark cell c as fixed (assigned to node u)
            forced_choice[u] = c;  // Record the forced assignment

            // Propagate constraint: remove cell c from candidates of neighboring nodes (indices v sharing candidate c)
            if (cell_to_indices.count(c))
            { // Check if cell 'c' is a candidate elsewhere
                for (int v : cell_to_indices[c])
                {
                    if (v == u || is_forced[v])
                        continue; // Skip self or nodes already forced

                    // Find index of cell c in candidates_v
                    int remove_idx = -1;
                    auto &candidates_v = Cprime[v];
                    for (int idx = 0; idx < candidates_v.size(); ++idx)
                    {
                        if (candidates_v[idx] == c)
                        {
                            remove_idx = idx;
                            break;
                        }
                    }

                    // If cell c was found in candidates_v
                    if (remove_idx != -1)
                    {
                        // Efficiently remove element by swapping with last element then popping back.
                        // This changes order but order is irrelevant for candidate sets.
                        swap(candidates_v[remove_idx], candidates_v.back());
                        candidates_v.pop_back();
                        Cprime_size[v]--; // Update tracked size

                        if (Cprime_size[v] == 0)
                        { // If v now has no candidates left
                            possible = false;
                            break; // Path impossible
                        }
                        if (Cprime_size[v] == 1)
                        {                        // If v now has only one candidate
                            q.push_back(v);      // Add v to queue for processing
                            is_forced[v] = true; // Mark v as forced
                        }
                    }
                }
            }
            if (!possible)
                break; // Exit loop early if impossibility detected
        }

        // If path determined impossible during simplification
        if (!possible)
        {
            cout << 0 << "\n";
            continue;
        }

        // Step 3: Build component graph for remaining non-forced nodes (those with |Cprime|=2)
        adj.assign(k + 1, vector<int>());         // Initialize adjacency list for the component graph
        vector<bool> visited_nodes(k + 1, false); // Track visited nodes for component finding BFS/DFS
        long long total_ways = 1;                 // Initialize total ways count

        // Build adjacency based on shared candidates among non-forced nodes
        // Only consider cells not already fixed by the simplification phase
        unordered_map<Cell, vector<int>, pair_hash> remaining_cell_to_indices;
        for (int i = 1; i <= k; ++i)
        {
            if (!is_forced[i])
            { // Only consider non-forced nodes
                for (const auto &cell : Cprime[i])
                {
                    // Only consider cells not already assigned (fixed)
                    if (fixed_cells.find(cell) == fixed_cells.end())
                    {
                        remaining_cell_to_indices[cell].push_back(i);
                    }
                }
            }
        }

        // Add edges between nodes sharing a remaining candidate cell
        for (auto const &[cell, indices] : remaining_cell_to_indices)
        {
            for (size_t i = 0; i < indices.size(); ++i)
            {
                for (size_t j = i + 1; j < indices.size(); ++j)
                {
                    adj[indices[i]].push_back(indices[j]);
                    adj[indices[j]].push_back(indices[i]);
                }
            }
        }

        // Step 4: Process connected components using BFS to find nodes and backtracking to count ways
        for (int i = 1; i <= k; ++i)
        {
            // If node i is not forced and not yet visited (start of a new component)
            if (!is_forced[i] && !visited_nodes[i])
            {
                component_nodes.clear(); // Reset list for the new component
                vector<int> q_bfs;       // Queue for BFS traversal within component
                q_bfs.push_back(i);
                visited_nodes[i] = true; // Mark starting node as visited
                int head_bfs = 0;

                // Perform BFS to find all nodes in the current component
                while (head_bfs < q_bfs.size())
                {
                    int u = q_bfs[head_bfs++];
                    component_nodes.push_back(u); // Add node to the component list

                    // Use set to handle duplicate neighbors potentially added to adj list
                    unordered_set<int> neighbors;
                    for (int v : adj[u])
                    {
                        neighbors.insert(v);
                    }

                    for (int v : neighbors)
                    { // Iterate unique neighbors
                        // Add neighbor to queue if it's part of the graph (not forced) and not visited
                        if (!is_forced[v] && !visited_nodes[v])
                        {
                            visited_nodes[v] = true;
                            q_bfs.push_back(v);
                        }
                    }
                }

                // Solve the component using backtracking
                current_assignment.clear();                        // Clear assignment map for the new component
                assigned_cells_in_component.clear();               // Clear the set of assigned cells
                long long component_ways = backtrack_component(0); // Start backtracking

                // Multiply total ways by the ways for this component (modulo MOD)
                total_ways = (total_ways * component_ways) % MOD;
            }
        }

        // Output the final total number of ways modulo MOD
        cout << total_ways << "\n";
    }
    return 0;
}