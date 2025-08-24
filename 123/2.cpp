#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <sstream>

// 这是本题的标准解法 (STD)，用于生成正确的 .out 文件
long double solve(long long n, int k)
{
    long double x = (long double)n * powl(100.0L, k - 1);
    long double s = roundl(sqrtl(x));
    if (s < 1.0L)
    {
        s = 1.0L;
    }
    long double ans = (x + s * s) / (2.0L * s) / powl(10.0L, k - 1);
    return ans;
}

int main()
{
    // 高质量随机数生成器
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);
    std::uniform_int_distribution<long long> dist_n(1, 1000000);
    std::uniform_int_distribution<int> dist_k(1, 16);
    std::uniform_int_distribution<int> dist_k_hard(9, 16);
    std::uniform_int_distribution<int> dist_t_small(1000, 5000);
    std::uniform_int_distribution<int> dist_t_large(90000, 100000);

    int num_files = 50;

    for (int i = 1; i <= num_files; ++i)
    {
        std::stringstream ss;
        ss << std::setw(2) << std::setfill('0') << i;
        std::string in_filename = ss.str() + ".in";
        std::string out_filename = ss.str() + ".out";

        std::ofstream inFile(in_filename);
        std::ofstream outFile(out_filename);

        int T = 1; // 默认值

        // 设计并生成测试用例
        if (i <= 5)
        { // Case 1-5: 单一强力测试用例, 验证极限情况
            T = 1;
            long long N;
            int K;
            if (i == 1)
            {
                N = 1000000;
                K = 16;
            } // N, K 都最大
            else if (i == 2)
            {
                N = 999999;
                K = 16;
            }
            else if (i == 3)
            {
                N = 1;
                K = 16;
            } // N 最小, K 最大
            else if (i == 4)
            {
                N = 998001;
                K = 15;
            } // N 是大完全平方数
            else if (i == 5)
            {
                N = 2;
                K = 14;
            } // 经典非整数开方

            inFile << T << '\n';
            inFile << N << " " << K << '\n';
            outFile << std::fixed << std::setprecision(9) << solve(N, K) << '\n';
        }
        else if (i <= 10)
        { // Case 6-10: 样例和简单情况
            if (i == 6)
            { // 样例文件
                T = 4;
                inFile << T << '\n';
                std::vector<std::pair<long long, int>> cases = {{2, 1}, {2, 2}, {2, 4}, {3, 5}};
                for (auto const &[n_val, k_val] : cases)
                {
                    inFile << n_val << " " << k_val << '\n';
                    outFile << std::fixed << std::setprecision(9) << solve(n_val, k_val) << '\n';
                }
            }
            else
            {
                T = 1;
                long long N;
                int K;
                if (i == 7)
                {
                    N = 1;
                    K = 1;
                }
                else if (i == 8)
                {
                    N = 1000000;
                    K = 1;
                }
                else if (i == 9)
                {
                    N = 4;
                    K = 1;
                }
                else if (i == 10)
                {
                    N = 3;
                    K = 1;
                }
                inFile << T << '\n';
                inFile << N << " " << K << '\n';
                outFile << std::fixed << std::setprecision(9) << solve(N, K) << '\n';
            }
        }
        else if (i <= 30)
        { // Case 11-30: 中等数量的多组测试
            T = dist_t_small(rng);
            inFile << T << '\n';
            for (int t_case = 0; t_case < T; ++t_case)
            {
                long long N = dist_n(rng);
                int K = dist_k(rng);
                inFile << N << " " << K << '\n';
                outFile << std::fixed << std::setprecision(9) << solve(N, K) << '\n';
            }
        }
        else
        { // Case 31-50: 大量测试用例, 强力卡性能
            T = dist_t_large(rng);
            inFile << T << '\n';
            for (int t_case = 0; t_case < T; ++t_case)
            {
                long long N = dist_n(rng);
                int K = dist_k_hard(rng); // 在大量测试中混入高难度K值
                inFile << N << " " << K << '\n';
                outFile << std::fixed << std::setprecision(9) << solve(N, K) << '\n';
            }
        }

        inFile.close();
        outFile.close();

        std::cout << "Generated " << in_filename << " and " << out_filename << " (T=" << T << ")" << std::endl;
    }

    std::cout << "\nSuccessfully generated " << num_files << " pairs of test files." << std::endl;

    return 0;
}