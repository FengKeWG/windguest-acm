/*
以下代码是AI测试代码！
以下代码是AI测试代码！
以下代码是AI测试代码！
以下代码是AI测试代码！
以下代码是AI测试代码！
以下代码是AI测试代码！
以下代码是AI测试代码！
以下代码是AI测试代码！
以下代码是AI测试代码！
*/
#include <bits/stdc++.h>
using namespace std;

// 判海：名称包含(不区分大小写) "OCEAN"
static bool is_ocean_name(const string &s)
{
    string t;
    t.reserve(s.size());
    for (char c : s)
    {
        t.push_back((char)tolower((unsigned char)c));
    }
    return t.find("ocean") != string::npos;
}

struct PairHash
{
    size_t operator()(const pair<int, int> &p) const noexcept
    {
        return (uint64_t(uint32_t(p.first)) << 32) ^ uint32_t(p.second);
    }
};

// 全局缓存：已查询的方格海/陆结果；以及已处理过（对该岛已做过洪泛）的标记
static unordered_map<pair<int, int>, char, PairHash> knownBiome; // 'S' 海, 'L' 陆
static unordered_set<pair<int, int>, PairHash> processedLand;    // 该细胞所在岛已处理

// 交互：查询 (x,y) 群系，带缓存
static string ask_biome_raw(long long x, long long y)
{
    cout << "? " << x << " " << y << endl;
    string s;
    if (!(cin >> s))
        exit(0);
    return s;
}

static bool is_ocean_cached(int x, int y)
{
    auto key = make_pair(x, y);
    auto it = knownBiome.find(key);
    if (it != knownBiome.end())
        return it->second == 'S';
    string s = ask_biome_raw(x, y);
    bool sea = is_ocean_name(s);
    knownBiome[key] = sea ? 'S' : 'L';
    return sea;
}

// 洪泛：从某个陆地起点，BFS 扩张；
// - 早停：当累计陆地数 >= K 即返回 true；
// - 仅从“陆地结点”向外扩张（海水不扩张），避免遍历整窗；
// - 结束后把该连通块的陆地全部标记为 processed，避免再次 BFS。
static bool flood_fill_check(int sx, int sy, int K, int L)
{
    const int dir4[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    unordered_set<pair<int, int>, PairHash> vis;
    vis.reserve(4096);
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis.insert({sx, sy});
    int cntLand = 0;
    vector<pair<int, int>> landCells;
    landCells.reserve(K + 256);
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        bool sea = is_ocean_cached(x, y);
        if (sea)
            continue; // 海水不扩张
        landCells.push_back({x, y});
        if (++cntLand >= K)
        {
            // 提前返回，不必把整个岛遍历完；但仍把已访问陆地标记 processed
            for (auto &c : landCells)
                processedLand.insert(c);
            return true;
        }
        for (auto d : dir4)
        {
            int nx = x + d[0], ny = y + d[1];
            if (abs(nx) > 1000000 || abs(ny) > 1000000)
                continue;
            if (abs(nx) > L || abs(ny) > L)
                continue;
            pair<int, int> nk = {nx, ny};
            if (!vis.count(nk))
            {
                vis.insert(nk);
                q.emplace(nx, ny);
            }
        }
    }
    // 未达到 K，标记该连通块已处理，后续不再重复洪泛
    for (auto &c : landCells)
        processedLand.insert(c);
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int K;
    if (!(cin >> K))
        return 0;

    auto spiral_ring = [&](int r, auto handle)
    {
        long long x = -r, y = -r;
        if (r == 0)
        {
            handle(0, 0);
            return;
        }
        for (x = -r, y = -r; x <= r; ++x)
            handle((int)x, (int)y); // 底边
        for (x = r, y = -r + 1; y <= r; ++y)
            handle((int)x, (int)y); // 右边
        for (x = r - 1, y = r; x >= -r; --x)
            handle((int)x, (int)y); // 顶边
        for (x = -r, y = r - 1; y > -r; --y)
            handle((int)x, (int)y); // 左边
    };

    const int r_margin = 5;
    for (int r = 0; r <= 1000; ++r)
    {
        bool stop = false;
        spiral_ring(r, [&](int x, int y)
                    {
			if(stop) return;
			// 已处理过该点所在岛？跳过
			if(processedLand.count({x,y})) return;
			// 先看缓存，不是海才可能洪泛
			bool sea = is_ocean_cached(x,y);
			if(sea) return;
			int L = max(r + r_margin, 16);
			if(flood_fill_check(x,y,K,L)){
				cout << "! " << x << " " << y << endl;
				stop = true;
			} });
        if (stop)
            return 0;
    }
    // 兜底（理论上不会触发）
    cout << "! 0 0" << endl;
    return 0;
}