#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map> // Not strictly necessary with current implementation but good to include if used potentially
#include <vector>
#include <set> // Using set for adjacency list simplifies handling potential duplicate edges and ensures uniqueness

using namespace std;

// Global variables reused across test cases within main() execution
// Need to be reset/resized for each test case inside solve()
vector<vector<int>> adj;  // Adjacency list for the original tree T (uses vector for initial input)
vector<int> subtree_size; // Stores subtree sizes during DFS on the modified tree T'
vector<int> post_order;   // Stores vertices in post-order traversal of T'
vector<bool> visited;     // Tracks visited vertices during DFS runs

/**
 * @brief Performs Depth First Search to compute subtree sizes rooted at 'u'.
 * It assumes the graph is represented by adjacency sets 'current_adj_set'.
 * visited[] array tracks visited nodes within the current DFS call to prevent infinite loops and re-computation.
 * subtree_size[] array stores the computed sizes.
 *
 * @param u Current vertex
 * @param p Parent vertex in DFS tree (to avoid traversing back up)
 * @param current_adj_set Adjacency list (using sets) of the graph T'
 * @param n_original Original number of vertices (N), used for array bounds
 */
void dfs_size(int u, int p, const vector<set<int>> &current_adj_set, int n_original)
{
    // Base case and cycle/revisit check: If node invalid, out of bounds, or already visited in this run, return.
    if (u <= 0 || u > n_original || visited[u])
    {
        return;
    }
    visited[u] = true;   // Mark current node as visited for this DFS run
    subtree_size[u] = 1; // Initialize size for node u itself

    // Safety check for bounds on adjacency list access
    if (u >= current_adj_set.size())
        return;

    // Explore neighbors
    for (int v : current_adj_set[u])
    {
        if (v != p)
        {                                                // Avoid going back to the parent
            dfs_size(v, u, current_adj_set, n_original); // Recursive call for child v
            subtree_size[u] += subtree_size[v];          // Accumulate child subtree size into parent's size
        }
    }
}

/**
 * @brief Calculates the maximum possible sum of path lengths between paired vertices in tree T'.
 * This sum is known to be equal to Sum_{edges e} min(|C1|, |C2|), where C1, C2 are component sizes upon removing e.
 * This function computes this sum based on subtree sizes calculated from a DFS rooted at 'root'.
 *
 * @param n_prime Number of vertices in T' (n-1)
 * @param current_adj_set Adjacency list (using sets) of T'
 * @param root The vertex chosen as the root for the DFS size calculation
 * @param n_original Original number of vertices (N) for array sizing
 * @return The maximum possible sum of distances.
 */
long long calculate_max_dist_sum(int n_prime, const vector<set<int>> &current_adj_set, int root, int n_original)
{
    if (n_prime <= 1)
        return 0; // Trivial case: 0 or 1 vertex results in sum 0

    // Reset global state for subtree size calculation
    subtree_size.assign(n_original + 1, 0);
    visited.assign(n_original + 1, false); // Reset visited flags for the new dfs_size run

    dfs_size(root, 0, current_adj_set, n_original); // Compute subtree sizes starting from the chosen root

    long long current_sum = 0;
    // The sum is computed over all edges. In a DFS tree, each edge corresponds to a non-root node and its parent.
    // The edge connects the subtree rooted at the node to the rest of the tree.
    // The sizes of the two components are subtree_size[i] and n_prime - subtree_size[i].
    for (int i = 1; i <= n_original; ++i)
    {
        // Check if node i was visited (exists in the component reachable from root) and is not the root itself
        if (visited[i] && i != root)
        {
            current_sum += min((long long)subtree_size[i], (long long)n_prime - subtree_size[i]);
        }
    }
    return current_sum;
}

/**
 * @brief Performs Depth First Search to obtain a post-order traversal of the vertices in T'.
 * Stores the traversal order in the global `post_order` vector.
 *
 * @param u Current vertex
 * @param p Parent vertex in DFS tree
 * @param current_adj_set Adjacency list (using sets) of T'
 */
void dfs_post_order(int u, int p, const vector<set<int>> &current_adj_set)
{
    visited[u] = true; // Mark visited for this traversal run
    // Safety bounds check
    if (u >= current_adj_set.size())
        return;

    // Explore neighbors
    for (int v : current_adj_set[u])
    {
        if (v != p && !visited[v])
        { // Process unvisited children
            dfs_post_order(v, u, current_adj_set);
        }
    }
    post_order.push_back(u); // Add vertex 'u' to post-order list after all its children have been processed
}

/**
 * @brief Solves a single test case.
 * Reads the tree structure, iterates through all possible edge removals,
 * calculates the maximum distance sum for each resulting tree T', identifies the best edge removal,
 * and finally computes and prints the required edge and coloring.
 */
void solve()
{
    int n; // Number of vertices (odd)
    cin >> n;
    adj.assign(n + 1, vector<int>()); // Resize and clear adjacency list for the original tree T
    vector<pair<int, int>> edges;     // Stores edges of T for iteration
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    long long max_total_dist = -1;       // Initialize max sum found so far
    pair<int, int> best_edge = {-1, -1}; // Track the edge that yields the max sum

    // Iterate through all edges of T to find the optimal one to remove
    for (const auto &edge : edges)
    {
        int u1 = edge.first;
        int v1 = edge.second;

        int a_prime = min(u1, v1); // The vertex that remains
        int b_prime = max(u1, v1); // The vertex that is removed

        // Construct T' using adjacency sets (vector<set<int>>)
        // Sets automatically handle potential duplicate edges from the construction logic
        vector<set<int>> current_adj_set(n + 1);
        vector<int> nodes_in_T_prime; // Keep track of vertices remaining in T'
        for (int i = 1; i <= n; ++i)
        {
            if (i != b_prime)
                nodes_in_T_prime.push_back(i);
        }

        // 1. Add edges from the original graph T that do not involve the removed vertex b_prime
        for (const auto &e : edges)
        {
            int x = e.first;
            int y = e.second;
            if (x != b_prime && y != b_prime)
            {
                current_adj_set[x].insert(y);
                current_adj_set[y].insert(x);
            }
        }

        // 2. Reattach neighbors of b_prime (excluding a_prime) directly to a_prime
        for (int neighbor : adj[b_prime])
        {
            if (neighbor != a_prime)
            { // Check neighbor is not a_prime
                // Ensure neighbor still exists (it must unless neighbor == b_prime, which is impossible)
                if (neighbor != b_prime)
                {
                    current_adj_set[a_prime].insert(neighbor);
                    current_adj_set[neighbor].insert(a_prime);
                }
            }
        }

        // If T' potentially becomes empty (only happens if n=1 initially, but problem says n>=3)
        if (nodes_in_T_prime.empty())
        {
            continue;
        }

        // Calculate the potential maximum distance sum for this constructed T'
        int root = nodes_in_T_prime[0]; // Choose an arbitrary existing node as root for DFS
        long long current_total_dist = calculate_max_dist_sum(n - 1, current_adj_set, root, n);

        // Update the best edge found if the current edge removal yields a larger sum
        if (current_total_dist > max_total_dist)
        {
            max_total_dist = current_total_dist;
            best_edge = {u1, v1};
        }
    }

    // Output the identified best edge pair (u, v)
    cout << best_edge.first << " " << best_edge.second << endl;

    // Reconstruct the final T' corresponding to the 'best_edge' to determine the coloring
    int a_prime_final = min(best_edge.first, best_edge.second);
    int b_prime_final = max(best_edge.first, best_edge.second);

    vector<set<int>> final_adj_set(n + 1); // Adjacency set for the final T'
    vector<int> nodes_in_final_T_prime;    // Vertices in the final T'
    for (int i = 1; i <= n; ++i)
    {
        if (i != b_prime_final)
            nodes_in_final_T_prime.push_back(i);
    }
    // Rebuild the final graph T' structure (same logic as above)
    for (const auto &e : edges)
    {
        int x = e.first;
        int y = e.second;
        if (x != b_prime_final && y != b_prime_final)
        {
            final_adj_set[x].insert(y);
            final_adj_set[y].insert(x);
        }
    }
    for (int neighbor : adj[b_prime_final])
    {
        if (neighbor != a_prime_final)
        {
            if (neighbor != b_prime_final)
            {
                final_adj_set[a_prime_final].insert(neighbor);
                final_adj_set[neighbor].insert(a_prime_final);
            }
        }
    }

    // Compute the post-order traversal for the final T'
    post_order.clear();           // Clear global post_order list from previous runs
    visited.assign(n + 1, false); // Reset visited flags for the final DFS post-order run
    if (!nodes_in_final_T_prime.empty())
    {
        int root_final = nodes_in_final_T_prime[0];   // Choose root for final DFS
        dfs_post_order(root_final, 0, final_adj_set); // Compute post order traversal
    }
    else
    {
        // Handle error case: T' is unexpectedly empty.
    }

    // Assign colors based on the post-order pairing strategy
    vector<int> colors(n + 1, 0); // Initialize color array (0 indicates no color/removed node)
    colors[b_prime_final] = 0;    // The removed vertex b_prime gets color 0
    int k = (n - 1) / 2;          // Number of distinct colors (pairs) needed

    // Safety check: ensure post_order list has the expected number of vertices (n-1)
    // If not, something went wrong (e.g., T' was disconnected), though this shouldn't happen with the described operation.
    if (post_order.size() != n - 1)
    {
        // cerr << "Warning: Post order size mismatch. Expected " << n-1 << ", got " << post_order.size() << endl;
    }

    // Pair vertices: i-th vertex in post-order with (i+k)-th vertex
    for (int i = 0; i < k; ++i)
    {
        // Safety check for array bounds before accessing post_order elements
        if (i < post_order.size() && i + k < post_order.size())
        {
            colors[post_order[i]] = i + 1; // Assign color i+1 to the pair
            colors[post_order[i + k]] = i + 1;
        }
        else
        {
            // Error handling for unexpected index out of bounds
            // cerr << "Error: Index out of bounds in post_order pairing." << endl;
        }
    }

    // Output the final coloring array
    for (int i = 1; i <= n; ++i)
    {
        cout << colors[i] << (i == n ? "" : " ");
    }
    cout << endl;
}

/**
 * @brief Main function: handles multiple test cases.
 */
int main()
{
    ios_base::sync_with_stdio(false); // Disable synchronization with C stdio for faster I/O
    cin.tie(NULL);                    // Untie cin from cout for potentially faster input operations
    int t;                            // Number of test cases
    cin >> t;
    while (t--)
    {
        solve(); // Solve each test case
    }
    return 0;
}