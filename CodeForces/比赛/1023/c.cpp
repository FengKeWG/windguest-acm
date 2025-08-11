#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long max_subarray_sum(const vector<long long> &a)
{
    long long max_so_far = -2e18; // Needs to handle negative values
    long long current_max = 0;
    bool all_negative = true;
    long long min_val = -1e18 - 7;

    for (long long x : a)
    {
        if (x >= 0)
            all_negative = false;
        max_so_far = max(max_so_far, x); // In case all numbers are negative
    }

    if (all_negative)
        return max_so_far;

    max_so_far = 0; // For case with non-negative values
    for (long long x : a)
    {
        current_max += x;
        if (current_max < 0)
            current_max = 0;
        max_so_far = max(max_so_far, current_max);
    }

    return max_so_far;
}

long long max_subarray_sum_general(const vector<long long> &a)
{
    long long max_so_far = -3e18; // Sufficiently small
    long long current_max = -3e18;
    if (a.empty())
        return -3e18;

    max_so_far = current_max = a[0];
    for (size_t i = 1; i < a.size(); ++i)
    {
        current_max = max(a[i], current_max + a[i]);
        max_so_far = max(max_so_far, current_max);
    }
    return max_so_far;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<long long> a(n);
        vector<int> zero_indices;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (s[i] == '0')
            {
                zero_indices.push_back(i);
            }
        }

        vector<long long> p_prime(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            p_prime[i + 1] = p_prime[i] + (s[i] == '1' ? a[i] : 0);
        }

        vector<int> z_indices = zero_indices;
        z_indices.insert(z_indices.begin(), -1); // Add -1 as z_0
        z_indices.push_back(n);                  // Add n as z_{t+1}
        int t_val = zero_indices.size();

        bool possible = true;

        // Check max subarray sum within segments of '1's
        for (int i = 0; i <= t_val; ++i)
        {
            int start_idx = z_indices[i] + 1;
            int end_idx = z_indices[i + 1] - 1;
            if (start_idx <= end_idx)
            {
                vector<long long> segment_a;
                for (int j = start_idx; j <= end_idx; ++j)
                {
                    segment_a.push_back(a[j]);
                }
                long long max_sum = max_subarray_sum_general(segment_a);
                if (max_sum > k)
                {
                    possible = false;
                    break;
                }
            }
        }

        if (!possible)
        {
            cout << "No\n";
            continue;
        }

        vector<long long> min_p_prime(t_val + 1);
        vector<long long> max_p_prime(t_val + 1);

        for (int i = 0; i <= t_val; ++i)
        {
            long long current_min = 2e18;
            long long current_max = -2e18;
            bool initialized = false;
            for (int j = z_indices[i] + 1; j <= z_indices[i + 1]; ++j)
            {
                if (!initialized)
                {
                    current_min = p_prime[j];
                    current_max = p_prime[j];
                    initialized = true;
                }
                else
                {
                    current_min = min(current_min, p_prime[j]);
                    current_max = max(current_max, p_prime[j]);
                }
            }
            min_p_prime[i] = current_min;
            max_p_prime[i] = current_max;
        }

        // For i=0, range [z_0, z_1-1]. prefix sum indices 0 to z_1-1
        // For i=t_val, range [z_t, z_{t+1}-1]. prefix sum indices z_t to n.
        // Prefixes $P'_0...P'_n$. $z_0=-1, z_{t+1}=n$.
        // Range for $minP'_i, maxP'_i$ should be $[z_i+1, z_{i+1}]$. $P'$ index $0 \dots n$.
        // If $i=0$, range $[z_0+1, z_1]=[0, z_1]$. Indices for $P'$ is $0 \dots z_1$. $P'_0, \dots, P'_{z_1}$.
        // If $i=t$, range $[z_t+1, z_{t+1}]=[z_t+1, n]$. Indices for $P'$ is $z_t+1 \dots n$. $P'_{z_t+1}, \dots, P'_n$.
        // For $0 < i < t$, range $[z_i+1, z_{i+1}]$. $P'_{z_i+1}, \dots, P'_{z_{i+1}}$.

        min_p_prime.assign(t_val + 1, 2e18);
        max_p_prime.assign(t_val + 1, -2e18);

        for (int i = 0; i <= t_val; ++i)
        {
            int start_p = z_indices[i] + 1;
            int end_p = z_indices[i + 1];
            if (start_p <= end_p)
            {
                for (int j = start_p; j <= end_p; ++j)
                {
                    min_p_prime[i] = min(min_p_prime[i], p_prime[j]);
                    max_p_prime[i] = max(max_p_prime[i], p_prime[j]);
                }
            }
            else
            { // Empty segment, e.g., consecutive zeros z_i, z_{i+1}=z_i+1. P' values are constant.
                min_p_prime[i] = p_prime[start_p - 1];
                max_p_prime[i] = p_prime[start_p - 1];
            }
        }

        vector<long long> Q(t_val + 1, 0);
        vector<long long> min_val_so_far(t_val + 1);

        min_val_so_far[0] = Q[0] + min_p_prime[0];

        for (int j = 1; j <= t_val; ++j)
        {
            long long m_ij = max_p_prime[j] - min_p_prime[j]; // Placeholder, this is not M_{i,j} for i=j

            Q[j] = k - max_p_prime[j] + min_val_so_far[j - 1];
            min_val_so_far[j] = min(min_val_so_far[j - 1], Q[j] + min_p_prime[j]);
        }

        // Verify constraints Q_j - Q_i <= k - M_{i,j} for i <= j
        for (int i = 0; i <= t_val; ++i)
        {
            for (int j = i; j <= t_val; ++j)
            {
                long long m_ij_val;
                if (i == j)
                { // Max subarray sum on a' segment z_i+1 ... z_{i+1}-1
                    int start_idx = z_indices[i] + 1;
                    int end_idx = z_indices[i + 1] - 1;
                    if (start_idx <= end_idx)
                    {
                        vector<long long> segment_a;
                        for (int l = start_idx; l <= end_idx; ++l)
                            segment_a.push_back(a[l]);
                        m_ij_val = max_subarray_sum_general(segment_a);
                    }
                    else
                    {
                        m_ij_val = -3e18; // Empty subarray
                    }
                }
                else
                { // i < j
                    m_ij_val = max_p_prime[j] - min_p_prime[i];
                }
                if (Q[j] - Q[i] > k - m_ij_val)
                {
                    possible = false;
                    break;
                }
            }
            if (!possible)
                break;
        }

        if (!possible)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
            vector<long long> result_a = a;
            for (int i = 0; i < t_val; ++i)
            {
                result_a[zero_indices[i]] = Q[i + 1] - Q[i];
            }
            for (int i = 0; i < n; ++i)
            {
                cout << result_a[i] << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }
    return 0;
}