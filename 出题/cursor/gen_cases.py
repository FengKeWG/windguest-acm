import os
import random
import math

COORD_MIN, COORD_MAX = -10**6, 10**6

# 面积与距离工具

def area_from_r(r):
    return (2*r + 1) * (2*r + 1)


def r_from_min_area(min_area):
    # 最小 r 使得 (2r+1)^2 >= min_area
    if min_area <= 1:
        return 0
    return max(0, int(math.ceil((math.sqrt(min_area) - 1) / 2.0)))


def cheb_dist_to_origin(cx, cy, r):
    dx = max(0, abs(cx) - r)
    dy = max(0, abs(cy) - r)
    return max(dx, dy)


def non_overlap(new_cx, new_cy, new_r, islands):
    # 两 L_inf 正方形不重叠且不4-连通：中心切比雪夫距离 > r1 + r2 + 1
    for (cx, cy, r) in islands:
        if max(abs(new_cx - cx), abs(new_cy - cy)) <= (new_r + r + 1):
            return False
    return True


def clamp_center(c, r):
    return max(COORD_MIN + r, min(COORD_MAX - r, c))


def place_island_at_distance(rnd, target_d, r, islands, max_attempt=2000):
    # 构造使得该岛到原点的最近切比雪夫距离恰为 target_d 的中心 (cx, cy)
    # 构造方式：将中心放在 x 或 y 轴方向： (±(target_d + r), t) 或 (t, ±(target_d + r))，|t| ≤ target_d + r
    for _ in range(max_attempt):
        axis = rnd.randint(0, 1)  # 0: x 轴定位；1: y 轴定位
        sign = rnd.choice([-1, 1])
        t = rnd.randint(-(target_d + r), target_d + r)
        if axis == 0:
            cx = clamp_center(sign * (target_d + r), r)
            cy = clamp_center(t, r)
        else:
            cx = clamp_center(t, r)
            cy = clamp_center(sign * (target_d + r), r)
        if non_overlap(cx, cy, r, islands):
            return (cx, cy)
    return None


def place_random_island(rnd, r, islands, span=10**6, max_attempt=5000):
    # 任意位置（满足边界且不重叠）
    for _ in range(max_attempt):
        cx = clamp_center(rnd.randint(COORD_MIN + r, COORD_MAX - r), r)
        cy = clamp_center(rnd.randint(COORD_MIN + r, COORD_MAX - r), r)
        if non_overlap(cx, cy, r, islands):
            return (cx, cy)
    return None


def gen_one(idx):
    rnd = random.Random(20250818 + idx)

    # 分组难度与参数区间，保证标准做法（螺旋+早停洪泛）<= 3e4 查询
    if 1 <= idx <= 10:
        K = rnd.randint(1, 50)
        d_lo, d_hi = 0, 10
        decoy_small = rnd.randint(0, 3)
        decoy_mid = rnd.randint(0, 2)
        other_suitable = rnd.randint(0, 1)
        huge_islands = 0
    elif 11 <= idx <= 20:
        K = rnd.randint(50, 500)
        d_lo, d_hi = 10, 30
        decoy_small = rnd.randint(3, 10)
        decoy_mid = rnd.randint(2, 6)
        other_suitable = rnd.randint(1, 2)
        huge_islands = rnd.randint(0, 1)
    elif 21 <= idx <= 35:
        K = rnd.randint(500, 3000)
        d_lo, d_hi = 30, 55
        decoy_small = rnd.randint(10, 20)
        decoy_mid = rnd.randint(5, 10)
        other_suitable = rnd.randint(2, 3)
        huge_islands = rnd.randint(1, 2)
    elif 36 <= idx <= 45:
        K = rnd.randint(2000, 5000)
        d_lo, d_hi = 55, 75
        decoy_small = rnd.randint(15, 30)
        decoy_mid = rnd.randint(8, 16)
        other_suitable = rnd.randint(2, 4)
        huge_islands = rnd.randint(1, 3)
    else:
        K = rnd.randint(4000, 5000)
        d_lo, d_hi = 72, 78
        decoy_small = rnd.randint(20, 40)
        decoy_mid = rnd.randint(10, 20)
        other_suitable = rnd.randint(3, 5)
        huge_islands = rnd.randint(1, 4)

    target_d = rnd.randint(d_lo, d_hi)

    islands = []  # (cx, cy, r)

    # 主适宜岛：面积 >= K，且最近切比雪夫距离为 target_d
    r_need = r_from_min_area(K)
    r0 = r_need + rnd.randint(0, 5)
    pos = place_island_at_distance(rnd, target_d, r0, islands)
    if pos is None:
        # 退化处理：直接放到原点附近
        pos = (clamp_center(target_d + r0, r0), 0)
    islands.append((pos[0], pos[1], r0))

    # 迷惑性小岛：面积 < K，距离 <= target_d（更近但不适宜）
    if K >= 2:
        rmax_decoy = r_from_min_area(K - 1)
        # 确保严格 < K
        if area_from_r(rmax_decoy) >= K:
            rmax_decoy = max(0, rmax_decoy - 1)
        # 更小一些的多样性
        for _ in range(decoy_small):
            if rmax_decoy < 0:
                break
            r = rnd.randint(0, min(rmax_decoy, 6 + (K // 100)))
            d_dec = rnd.randint(0, target_d)
            p = place_island_at_distance(rnd, d_dec, r, islands)
            if p:
                islands.append((p[0], p[1], r))

    # 中等大小干扰：面积接近 K 但 < K，距离在 [max(0, target_d-5), target_d+2]
    if K >= 10:
        rmax_decoy2 = r_from_min_area(max(1, K - 1))
        if area_from_r(rmax_decoy2) >= K:
            rmax_decoy2 = max(0, rmax_decoy2 - 1)
        for _ in range(decoy_mid):
            r = max(0, rmax_decoy2 - rnd.randint(0, 2))
            d_dec = rnd.randint(max(0, target_d - 5), target_d + 2)
            p = place_island_at_distance(rnd, d_dec, r, islands)
            if p:
                islands.append((p[0], p[1], r))

    # 其它适宜岛：距离严格大于 target_d，防止最近适宜岛不唯一
    for _ in range(other_suitable):
        r_s = r_need + rnd.randint(0, 40)
        d_s = target_d + rnd.randint(3, 60)
        p = place_island_at_distance(rnd, d_s, r_s, islands)
        if p:
            islands.append((p[0], p[1], r_s))

    # 远处巨型岛：面积远大于 K，用于卡“不会早停的洪泛”
    for _ in range(huge_islands):
        r_h = rnd.randint(80, 400)
        d_h = target_d + rnd.randint(80, 2000)
        p = place_island_at_distance(rnd, d_h, r_h, islands)
        if not p:
            p = place_random_island(rnd, r_h, islands)
        if p:
            islands.append((p[0], p[1], r_h))

    # 额外随机小岛（纯噪声，不与主逻辑相关）
    extra_noise = rnd.randint(0, 50)
    attempts = 0
    while extra_noise > 0 and attempts < 20000 and len(islands) < 200:
        attempts += 1
        r = rnd.randint(0, 20)
        p = place_random_island(rnd, r, islands)
        if p:
            islands.append((p[0], p[1], r))
            extra_noise -= 1

    return K, islands


def main():
    # 在当前目录直接生成 1.in..50.in 与对应空 1.out..50.out（不创建任何子目录）
    for i in range(1, 51):
        K, islands = gen_one(i)
        in_path = f"{i}.in"
        out_path = f"{i}.out"
        with open(in_path, "w", encoding="utf-8") as f:
            f.write(f"{K} {len(islands)}\n")
            for (cx, cy, r) in islands:
                f.write(f"{cx} {cy} {r}\n")
        # 交互题：输出文件可为空占位
        open(out_path, "w").close()
    print("Generated 50 pairs: ./1.in..50.in and empty ./1.out..50.out")


if __name__ == "__main__":
    main()