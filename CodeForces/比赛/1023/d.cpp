#include <bits/stdc++.h>

#define endl '\n'
#define N 150005

using namespace std;

vector<int> g[N];
bool apple[N];
int par[N];
int dep[N];
int n;

void dfs_init(int u, int p, int d)
{
    par[u] = p;
    dep[u] = d;
    for (int v : g[u])
    {
        if (v != p)
        {
            dfs_init(v, u, d + 1);
        }
    }
}

bool check_fast(int u, int v)
{
    int cu = u, cv = v;

    int temp_depu = dep[u], temp_depv = dep[v];

    while (temp_depu > temp_depv)
    {
        if (!apple[cu])
            return false;
        cu = par[cu];
        temp_depu--;
    }

    while (temp_depv > temp_depu)
    {
        if (!apple[cv])
            return false;
        cv = par[cv];
        temp_depv--;
    }

    while (cu != cv)
    {

        if (!apple[cu])
            return false;
        if (!apple[cv])
            return false;
        cu = par[cu];
        cv = par[cv];
    }

    if (!apple[cu])
        return false;

    return true;
}

int get_path_len(int u, int v)
{
    int cu = u, cv = v;
    int temp_depu = dep[u], temp_depv = dep[v];
    int len = 0;

    while (temp_depu > temp_depv)
    {
        len++;
        cu = par[cu];
        temp_depu--;
    }

    while (temp_depv > temp_depu)
    {
        len++;
        cv = par[cv];
        temp_depv--;
    }

    while (cu != cv)
    {
        len += 2;
        cu = par[cu];
        cv = par[cv];
    }

    len++;
    return len;
}

void get_path_nodes(int u, int v, vector<int> &path)
{
    path.clear();
    vector<int> pu, pv;
    int cu = u;
    int cv = v;

    int temp_depu = dep[u], temp_depv = dep[v];

    while (temp_depu > temp_depv)
    {
        pu.push_back(cu);
        cu = par[cu];
        temp_depu--;
    }

    while (temp_depv > temp_depu)
    {
        pv.push_back(cv);
        cv = par[cv];
        temp_depv--;
    }

    while (cu != cv)
    {
        pu.push_back(cu);
        pv.push_back(cv);
        cu = par[cu];
        cv = par[cv];
    }

    pu.push_back(cu);

    path = pu;
    reverse(pv.begin(), pv.end());
    path.insert(path.end(), pv.begin(), pv.end());
}

struct PI
{
    int d = 0;
    int u = 0;
    int v = 0;

    bool operator<(const PI &o) const
    {
        if (d != o.d)
            return d < o.d;
        if (u != o.u)
            return u < o.u;
        return v < o.v;
    }
};

int main()
{

    cin.tie(0)->sync_with_stdio(0);

    int tt;
    cin >> tt;
    while (tt--)
    {
        cin >> n;

        for (int i = 1; i <= n; ++i)
        {
            g[i].clear();
            apple[i] = true;
            par[i] = 0;
            dep[i] = 0;
        }

        for (int i = 0; i < n - 1; ++i)
        {
            int u1, v1;
            cin >> u1 >> v1;
            g[u1].push_back(v1);
            g[v1].push_back(u1);
        }

        if (n > 0)
            dfs_init(1, 0, 0);

        int cnt = n;
        vector<tuple<int, int, int>> ans;
        vector<int> nodes;

        while (cnt > 0)
        {

            nodes.clear();
            for (int i = 1; i <= n; ++i)
            {
                if (apple[i])
                {
                    nodes.push_back(i);
                }
            }

            if (nodes.empty())
                break;

            PI b = {0, 0, 0};
            int best_u_orig = -1, best_v_orig = -1;

            for (size_t i = 0; i < nodes.size(); ++i)
            {
                int u_node = nodes[i];

                PI cur_single = {1, u_node, u_node};

                if (b < cur_single)
                {
                    b = cur_single;
                    best_u_orig = u_node;
                    best_v_orig = u_node;
                }

                for (size_t j = i + 1; j < nodes.size(); ++j)
                {
                    int v_node = nodes[j];

                    if (check_fast(u_node, v_node))
                    {
                        int curd = get_path_len(u_node, v_node);
                        int curu = u_node, curv = v_node;
                        if (curu < curv)
                            swap(curu, curv);
                        PI cur = {curd, curu, curv};

                        if (b < cur)
                        {
                            b = cur;
                            best_u_orig = u_node;
                            best_v_orig = v_node;
                        }
                    }
                }
            }

            if (b.d == 0)
            {

                break;
            }

            ans.emplace_back(b.d, b.u, b.v);

            vector<int> bp;
            get_path_nodes(best_u_orig, best_v_orig, bp);

            for (int node_on_path : bp)
            {
                if (apple[node_on_path])
                {
                    apple[node_on_path] = false;
                    cnt--;
                }
            }
        }

        for (size_t i = 0; i < ans.size(); ++i)
        {

            cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << (i == ans.size() - 1 ? "" : " ");
        }
        cout << '\n';
    }
    return 0;
}