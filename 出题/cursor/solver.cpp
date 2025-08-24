#include <bits/stdc++.h>
using namespace std;

static inline bool isOcean(const string &s) {
	for (char c : s) {
		if (c == 'O' || c == 'o') return s.find('O') != string::npos || s.find('o') != string::npos || s.find("OCEAN") != string::npos || s.find("ocean") != string::npos; // quick path
	}
	string t;
	t.reserve(s.size());
	for (char c : s) t.push_back((char)tolower((unsigned char)c));
	return t.find("ocean") != string::npos;
}

static inline bool queryIsLand(long long x, long long y) {
	cout << "? " << x << ' ' << y << '\n' << flush;
	string resp;
	if (!getline(cin, resp)) exit(0);
	return !isOcean(resp);
}

static inline long long ceil_div(long long a, long long b) {
	return (a + b - 1) / b;
}

// 从一个已在陆地上的点 (x0,y0) 出发，沿水平方向找左右边界（含边上的最后一个陆地坐标）
static pair<long long,long long> findHorizontalBounds(long long x0, long long y0) {
	// 向左指数扩展
	long long step = 1;
	while (queryIsLand(x0 - step, y0)) {
		if (step > (long long)1e6) break;
		step <<= 1;
	}
	long long L = x0 - step, R = x0; // 区间 (L, R] 里有陆地，L 处是海或越界
	// 二分找最左陆地
	while (L + 1 < R) {
		long long mid = (L + R) >> 1;
		if (queryIsLand(mid, y0)) R = mid; else L = mid;
	}
	long long leftMost = R;

	// 向右指数扩展
	step = 1;
	while (queryIsLand(x0 + step, y0)) {
		if (step > (long long)1e6) break;
		step <<= 1;
	}
	L = x0; R = x0 + step; // 区间 [L, R) 里有陆地，R 处是海或越界
	while (L + 1 < R) {
		long long mid = (L + R) >> 1;
		if (queryIsLand(mid, y0)) L = mid; else R = mid;
	}
	long long rightMost = L;
	return {leftMost, rightMost};
}

static pair<long long,long long> findVerticalBounds(long long x0, long long y0) {
	long long step = 1;
	while (queryIsLand(x0, y0 - step)) {
		if (step > (long long)1e6) break;
		step <<= 1;
	}
	long long L = y0 - step, R = y0;
	while (L + 1 < R) {
		long long mid = (L + R) >> 1;
		if (queryIsLand(x0, mid)) R = mid; else L = mid;
	}
	long long bottomMost = R;

	step = 1;
	while (queryIsLand(x0, y0 + step)) {
		if (step > (long long)1e6) break;
		step <<= 1;
	}
	L = y0; R = y0 + step;
	while (L + 1 < R) {
		long long mid = (L + R) >> 1;
		if (queryIsLand(x0, mid)) L = mid; else R = mid;
	}
	long long topMost = L;
	return {bottomMost, topMost};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long K;
	if(!(cin>>K)) return 0;
	string dummy; getline(cin, dummy); // consume endline

	// r_min = ceil((sqrt(K)-1)/2)
	double root = sqrt((long double)K);
	long long rmin = (long long)ceil((root - 1.0L) / 2.0L);
	long long T = 2 * rmin + 1; // 最小适宜岛屿的边长

	// 按格点 (i*T, j*T) 以增大的切比雪夫层数搜索，直到命中陆地（保证属于适宜岛屿）
	long long foundX = LLONG_MAX, foundY = LLONG_MAX;
	for (long long g = 0; ; ++g) {
		// 上下边
		for (long long i = -g; i <= g; ++i) {
			long long x = i * T;
			long long y1 = g * T;
			long long y2 = -g * T;
			if (g == 0) {
				if (queryIsLand(0, 0)) { foundX = 0; foundY = 0; break; }
			} else {
				if (queryIsLand(x, y1)) { foundX = x; foundY = y1; break; }
				if (queryIsLand(x, y2)) { foundX = x; foundY = y2; break; }
			}
		}
		if (foundX != LLONG_MAX) break;
		// 左右边（去除角点避免重复）
		if (g > 0) {
			for (long long j = -g + 1; j <= g - 1; ++j) {
				long long y = j * T;
				long long x1 = g * T;
				long long x2 = -g * T;
				if (queryIsLand(x1, y)) { foundX = x1; foundY = y; break; }
				if (queryIsLand(x2, y)) { foundX = x2; foundY = y; break; }
			}
			if (foundX != LLONG_MAX) break;
		}
	}

	// 已命中一个适宜岛屿，在其内部点 (foundX,foundY)。
	auto [xL, xR] = findHorizontalBounds(foundX, foundY);
	auto [yB, yT] = findVerticalBounds(foundX, foundY);
	long long cx = (xL + xR) / 2;
	long long cy = (yB + yT) / 2;
	// 可直接输出中心，或任意内部点
	cout << "! " << cx << ' ' << cy << '\n' << flush;
	return 0;
}

