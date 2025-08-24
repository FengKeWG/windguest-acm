#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

struct Island {
	long long cx;
	long long cy;
	long long r; // L_inf 半径（轴对齐正方形）
	long long area; // (2r+1)^2
	long long chebDistToOrigin; // 最近切比雪夫距离到 (0,0)
};

static const long long COORD_MIN = -1000000;
static const long long COORD_MAX =  1000000;
static const int MAX_QUERIES = 100000;

static const vector<string> OCEAN_BIOMES = {
	"OCEAN","DEEP_OCEAN","FROZEN_OCEAN","warm_ocean","lukewarm_OCEAN","cold_ocean"
};
static const vector<string> LAND_BIOMES = {
	"PLAINS","FOREST","DESERT","JUNGLE","SAVANNA","TAIGA","SWAMP","MOUNTAINS","BIRCH_FOREST","DARK_FOREST",
	"WOODLANDS","GRASSLAND","MEADOW","STEPPE","SHRUBLAND","MANGROVE","BADLANDS","CHERRY_GROVE","BAMBOO_JUNGLE","RIVERBANK"
};

// 简单哈希（确定性）
static inline uint64_t mix64(uint64_t x) {
	x ^= x >> 33;
	x *= 0xff51afd7ed558ccdULL;
	x ^= x >> 33;
	x *= 0xc4ceb9fe1a85ec53ULL;
	x ^= x >> 33;
	return x;
}

static inline long long absll(long long x){ return x >= 0 ? x : -x; }

// 点是否在某岛（L_inf 正方形）内
static inline bool pointInIsland(long long x, long long y, const Island& isl) {
	return max(absll(x - isl.cx), absll(y - isl.cy)) <= isl.r;
}

// 返回包含该点的岛索引（不应重叠；若重叠取第一个）
static int whichIsland(long long x, long long y, const vector<Island>& islands) {
	for (int i = 0; i < (int)islands.size(); ++i) {
		if (pointInIsland(x, y, islands[i])) return i;
	}
	return -1;
}

// 计算最近切比雪夫距离到 (0,0)（对 L_inf 正方形恰为下面公式）
static inline long long islandChebDistToOrigin(const Island& isl) {
	long long dx = max(0LL, absll(isl.cx) - isl.r);
	long long dy = max(0LL, absll(isl.cy) - isl.r);
	return max(dx, dy);
}

// 基于坐标返回群系名称（包含不区分大小写的 OCEAN 即海洋，否则陆地）
static string biomeAt(long long x, long long y, const vector<Island>& islands) {
	int idx = whichIsland(x, y, islands);
	uint64_t h = mix64((uint64_t)x * 1315423911ULL ^ (uint64_t)y * 11400714819323198485ULL);
	if (idx >= 0) {
		// 陆地
		string s = LAND_BIOMES[(size_t)(h % LAND_BIOMES.size())];
		return s;
	} else {
		// 海洋
		string s = OCEAN_BIOMES[(size_t)(h % OCEAN_BIOMES.size())];
		return s;
	}
}

int main(int argc, char* argv[]) {
	setName("Interactor for Manhunt island finder");
	registerInteraction(argc, argv);

	// 读取测试数据
	// 格式：
	// K M
	// cx cy r   （共 M 行）
	int K = inf.readInt(1, 5000, "K");
	int M = inf.readInt(1, 200, "M");
	vector<Island> islands(M);
	for (int i = 0; i < M; ++i) {
		long long cx = inf.readLong(COORD_MIN, COORD_MAX, "cx");
		long long cy = inf.readLong(COORD_MIN, COORD_MAX, "cy");
		long long r  = inf.readLong(0LL, 1000000LL, "r");
		islands[i].cx = cx;
		islands[i].cy = cy;
		islands[i].r  = r;
		islands[i].area = (2LL * r + 1) * (2LL * r + 1);
		islands[i].chebDistToOrigin = islandChebDistToOrigin(islands[i]);
	}

	// 计算最近的“适宜岛屿”（面积 >= K）之最小切比雪夫距离
	long long bestDist = -1;
	for (const auto& isl : islands) {
		if (isl.area >= K) {
			if (bestDist == -1 || isl.chebDistToOrigin < bestDist) {
				bestDist = isl.chebDistToOrigin;
			}
		}
	}
	if (bestDist == -1) {
		quitf(_fail, "No suitable island (area >= K) exists in test data.");
	}

	// 输出给交互库/选手程序的初始输入：K
	cout << K << endl;

	int queryCnt = 0;

	while (true) {
		if (ouf.eof()) {
			quitf(_pe, "Unexpected EOF from contestant.");
		}
		string op = ouf.readToken("[!?]");
		if (op == "?") {
			long long x = ouf.readLong(COORD_MIN, COORD_MAX, "x");
			long long y = ouf.readLong(COORD_MIN, COORD_MAX, "y");
			++queryCnt;
			if (queryCnt > MAX_QUERIES) {
				quitf(_wa, "Too many queries: %d > %d", queryCnt, MAX_QUERIES);
			}
			string resp = biomeAt(x, y, islands);
			cout << resp << endl; // 必须换行并flush
		} else if (op == "!") {
			long long ax = ouf.readLong(COORD_MIN, COORD_MAX, "ax");
			long long ay = ouf.readLong(COORD_MIN, COORD_MAX, "ay");
			// 校验答案
			int idx = whichIsland(ax, ay, islands);
			if (idx < 0) {
				quitf(_wa, "Answer (%lld,%lld) is in OCEAN.", ax, ay);
			}
			const Island& picked = islands[idx];
			if (picked.area < K) {
				quitf(_wa, "Answer is on an island with area %lld < K=%d.", picked.area, K);
			}
			if (picked.chebDistToOrigin != bestDist) {
				quitf(_wa, "Answer is not on the nearest suitable island. expected chebDist=%lld, got %lld.",
				      bestDist, picked.chebDistToOrigin);
			}
			quitf(_ok, "Accepted with %d queries.", queryCnt);
		} else {
			quitf(_pe, "Unknown operation token: '%s'. Expected '?' or '!'.", op.c_str());
		}
	}
}