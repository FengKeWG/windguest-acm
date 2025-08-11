#include <iostream>
#include <algorithm> // Required for std::min

// Function to compute the minimum sum based on the derived logic
long long solve()
{
    long long n; // Length of the array
    long long x; // Required XOR sum
    std::cin >> n >> x;

    // Base case: Array length is 1
    if (n == 1)
    {
        // The array must be a single element [a_1].
        // We need a_1 = x and a_1 > 0.
        if (x > 0)
        {
            // If x is positive, the array [x] satisfies the conditions.
            // The sum is x.
            return x;
        }
        else
        {
            // If x is 0, we need a_1 = 0. But elements must be positive.
            // No suitable array exists.
            return -1;
        }
    }

    // General case: Array length n >= 2
    if (n % 2 != 0)
    { // n is odd
        // Case 1: n is odd
        if (x == 0)
        {
            // Need XOR sum 0. All elements positive. n >= 3 because n is odd and >= 2.
            // Construction: [1, 2, 3, 1, ..., 1]. This array has length n.
            // It contains 1, 2, 3 and n-3 ones. All elements are positive.
            // XOR sum: 1 ^ 2 ^ 3 ^ (1 ^ ... ^ 1, n-3 times)
            // Since n is odd, n-3 is even. So (1 ^ ... ^ 1) = 0.
            // 1 ^ 2 ^ 3 = (01)_2 ^ (10)_2 ^ (11)_2 = (11)_2 ^ (11)_2 = 0.
            // Total XOR sum is 0 ^ 0 = 0.
            // Sum is 1 + 2 + 3 + (n-3)*1 = 6 + n - 3 = n + 3.
            // This is believed to be the minimum sum construction.
            return n + 3;
        }
        else
        { // x > 0
            // Construction 1: [x, 1, ..., 1] (n-1 ones)
            // Elements are positive since x > 0 and 1 > 0.
            // n is odd, so n-1 is even. The XOR sum of n-1 ones is 0.
            // Total XOR sum is x ^ 0 = x.
            // Sum is x + (n-1)*1 = x + n - 1.
            long long sum1 = x + n - 1;

            // Construction 2: [x^3, 1, 2, 1, ..., 1] (n-3 ones)
            // This construction requires n >= 3. Since n is odd and n>=2, this holds.
            // All elements must be positive. 1 > 0, 2 > 0. We need x^3 > 0. This holds if x != 3.
            // n is odd, so n-3 is even. The XOR sum of n-3 ones is 0.
            // Total XOR sum is (x^3) ^ 1 ^ 2 ^ 0 = (x^3) ^ (1^2) = (x^3) ^ 3 = x ^ (3^3) = x ^ 0 = x.
            // Sum is (x^3) + 1 + 2 + (n-3)*1 = (x^3) + 3 + n - 3 = (x^3) + n.
            // This construction is better than sum1 iff (x^3) + n < x + n - 1, which simplifies to (x^3) < x - 1.
            // This inequality holds if and only if x % 4 == 3 (i.e., the last two bits of x are 11).

            if (x == 3)
            {
                // If x=3, construction 2 is invalid because x^3 = 0. We must use construction 1.
                // Sum for x=3 is 3 + n - 1 = n + 2.
                return n + 2;
            }
            else
            {
                // If x > 0 and x != 3:
                if ((x % 4) == 3)
                {
                    // Both constructions are valid. Construction 2 is better or equal.
                    // Example: x=7, n=3. sum1 = 7+3-1=9. sum2 = (7^3)+3 = 4+3 = 7. min is 7.
                    // We take the minimum of the two sums.
                    long long sum2 = (x ^ 3) + n;
                    return std::min(sum1, sum2);
                }
                else
                {
                    // If x % 4 != 3, construction 2 is not better than construction 1.
                    // Use construction 1.
                    return sum1;
                }
            }
        }
    }
    else
    { // n is even
        // Case 2: n is even
        if (x == 1)
        {
            // Need XOR sum 1. All elements positive. n >= 2.
            // Construction: [2, 3, 1, ..., 1] (n-2 ones). Works for n >= 2.
            // If n=2, array is [2, 3]. Sum 5. Formula n+3=2+3=5.
            // If n>=4, array is [2, 3, 1...1]. n-2 is even. XOR sum = 2^3 ^ (1^...^1) = 1 ^ 0 = 1.
            // Sum is 2 + 3 + (n-2)*1 = 5 + n - 2 = n + 3.
            // The general formula n+3 works for all even n>=2.
            return n + 3;
        }
        else
        {   // x != 1 (this includes x=0)
            // Construction: [x^1, 1, ..., 1] (n-1 ones)
            // Elements must be positive. 1 > 0. Need x^1 > 0. This holds since x != 1 implies x^1 != 0.
            // n is even, so n-1 is odd. The XOR sum of n-1 ones is 1.
            // Total XOR sum is (x^1) ^ 1 = x ^ (1^1) = x ^ 0 = x.
            // Sum is (x^1) + (n-1)*1 = (x ^ 1) + n - 1.
            // This is believed to be the minimum sum construction.
            return (x ^ 1) + n - 1;
        }
    }
}

int main()
{
    // Use faster I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t; // Number of test cases
    std::cin >> t;
    while (t--)
    {
        // Solve each test case and print the result
        std::cout << solve() << "\n";
    }
    return 0;
}