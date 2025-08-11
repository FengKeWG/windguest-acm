#include <bits/stdc++.h> // 保留你的常用头文件

#define int long long // 使用 long long 以处理可能的大组件尺寸
#define endl '\n'
// #define N 200005 // N 这个宏定义在使用 vector 时不是必需的

using namespace std;

// 如果你需要自定义的快速读入函数，可以放在这里
// inline int read() { ... }

// --- 全局变量区域 ---
vector<vector<int>> adj;                // 块图的邻接表
vector<int> block_sizes;                // 存储每个块节点代表的 '0' 的数量
vector<bool> visited;                   // DFS/BFS 访问标记数组
map<pair<int, int>, int> block_node_id; // 映射 (块类型, 索引) -> 块图节点ID
// 块类型 Type: 0=Di (对角线), 1=Cj_up (列 j 上半部分), 2=Cj_down (列 j 下半部分)

int current_component_size; // 用于 DFS 计算当前连通分量大小

// --- 辅助函数 ---

// 安全获取块对应的节点ID。如果块不存在或大小为0（未创建节点），返回-1
int get_node_id(int type, int index)
{
    auto it = block_node_id.find({type, index});
    if (it != block_node_id.end())
    {
        return it->second; // 返回找到的节点ID
    }
    return -1; // 未找到对应节点
}

// 添加边（如果两个节点ID都有效）
void add_edge_if_valid(int u_id, int v_id)
{
    if (u_id != -1 && v_id != -1)
    {
        adj[u_id].push_back(v_id);
        adj[v_id].push_back(u_id); // 无向图
    }
}

// 深度优先搜索计算连通分量大小
void dfs(int u)
{
    visited[u] = true;
    current_component_size += block_sizes[u]; // 累加当前块的大小
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
}

// --- 主逻辑 ---

signed main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t; // 测试用例数量
    cin >> t;
    while (t--)
    {
        int n; // 字符串长度
        cin >> n;
        string s; // 二进制字符串 s
        cin >> s;

        // --- 每个测试用例开始时重置状态 ---
        block_node_id.clear(); // 清空块到节点ID的映射
        block_sizes.clear();   // 清空块大小列表
        adj.clear();           // 清空邻接表 (后面会 resize)
        visited.clear();       // 清空访问标记 (后面会 resize)

        vector<tuple<int, int, int>> potential_blocks; // 临时存储潜在的块信息 (类型, 索引, 大小)

        // 步骤 1: 识别所有潜在的块及其大小
        for (int i = 1; i <= n; ++i)
        { // 使用 1-based 索引方便计算大小
            if (s[i - 1] == '1')
            {
                // 如果 s[i-1] 是 '1', 则对角线上 (i, i) 是 '0' -> Di 块
                potential_blocks.emplace_back(0, i, 1LL); // 类型0, 索引i, 大小1
            }
            else
            {
                // 如果 s[i-1] 是 '0', 则列 i (索引 j=i) 有 '0' (除了对角线)
                // 创建 Cj_up 和 Cj_down 块 (j=i)
                potential_blocks.emplace_back(1, i, (int)i - 1); // 类型1, 索引i, 大小 i-1
                potential_blocks.emplace_back(2, i, (int)n - i); // 类型2, 索引i, 大小 n-i
            }
        }

        // 步骤 1.5: 为大小 > 0 的块分配节点ID，并存储大小
        int node_count = 0; // 块图中实际的节点数量
        for (const auto &block_info : potential_blocks)
        {
            int size = get<2>(block_info);
            if (size > 0)
            { // 只为非空块创建节点
                int type = get<0>(block_info);
                int index = get<1>(block_info);
                block_node_id[{type, index}] = node_count; // 映射 (类型, 索引) -> 节点ID
                block_sizes.push_back(size);               // 存储该节点ID对应的块大小
                node_count++;                              // 增加节点计数
            }
        }

        // 如果没有 '0' 块 (例如 n=1, s="0")
        if (node_count == 0)
        {
            cout << 0 << endl;
            continue; // 处理下一个测试用例
        }

        // 根据实际节点数量调整邻接表和访问数组大小
        adj.assign(node_count, vector<int>());
        visited.assign(node_count, false);

        // 步骤 2: 构建块图的边
        // 2a: 处理对角线块 Di 与相邻列块的连接
        for (int i = 1; i <= n; ++i)
        {
            if (s[i - 1] == '1')
            {                                 // Di 块存在
                int d_id = get_node_id(0, i); // 获取 Di 的节点 ID
                if (d_id == -1)
                    continue; // 如果 Di 大小为0 (不可能为Di)，跳过

                // 连接左边的列 C(i-1)_down (如果存在且 s[i-2]=='0')
                if (i > 1 && s[i - 2] == '0')
                {
                    int c_down_id = get_node_id(2, i - 1);
                    add_edge_if_valid(d_id, c_down_id);
                }
                // 连接右边的列 C(i+1)_up (如果存在且 s[i]=='0')
                if (i < n && s[i] == '0')
                {
                    int c_up_id = get_node_id(1, i + 1);
                    add_edge_if_valid(d_id, c_up_id);
                }
            }
        }

        // 2b: 处理相邻列块之间的连接 (Cc 和 C(c+1))
        for (int c = 1; c < n; ++c)
        {
            if (s[c - 1] == '0' && s[c] == '0')
            { // 只有两列都对应 s 中的 '0' 时才有连接
                // 连接 Cc_up 和 C(c+1)_up
                int c_up1_id = get_node_id(1, c);
                int c_up2_id = get_node_id(1, c + 1);
                add_edge_if_valid(c_up1_id, c_up2_id);

                // 连接 Cc_down 和 C(c+1)_down
                int c_down1_id = get_node_id(2, c);
                int c_down2_id = get_node_id(2, c + 1);
                add_edge_if_valid(c_down1_id, c_down2_id);
            }
        }

        // 步骤 3: 在块图上运行 DFS (或 BFS) 查找最大连通分量
        int max_size = 0; // 存储最大连通分量的大小
        for (int i = 0; i < node_count; ++i)
        {
            if (!visited[i])
            {
                current_component_size = 0;                       // 重置当前分量大小计数器
                dfs(i);                                           // 探索一个新分量
                max_size = max(max_size, current_component_size); // 更新最大值
            }
        }

        // 步骤 4: 输出结果
        cout << max_size << endl;
    }
    return 0;
}