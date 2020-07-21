#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int SIZE = 200001;
const int MAXST = 1 << 19;

struct MergesortTree {
    vector<int> a[MAXST];
    void construct() {
        for (int i = MAXST / 2 - 1; i > 0; i--) {
            vector<int> &c = a[i], &l = a[i * 2], &r = a[i * 2 + 1];
            a[i].resize(l.size() + r.size());
            for (int j = 0, p = 0, q = 0; j < c.size(); j++) {
                if (q == r.size() || (p < l.size() && l[p] < r[q]))
                    c[j] = l[p++];
                else
                    c[j] = r[q++];
            }
        }
    }

    int solve(int s, int e, int k, int node, int ns, int ne) {
        if (ne <= s || e <= ns) return 0;
        if (s <= ns && ne <= e) {
            return upper_bound(a[node].begin(), a[node].end(), k) - a[node].begin();
        }
        int mid = ns + ne >> 1;
        return solve(s, e, k, node * 2, ns, mid) + solve(s, e, k, node * 2 + 1, mid, ne);
    }
};

int n, m, c;
int color[SIZE];
int col[SIZE];
int in[SIZE], out[SIZE], cnt;
vector<int> g[SIZE];
MergesortTree st;

void dfs(int now) {
    if (in[now]) return;
    in[now] = ++cnt;
    col[cnt] = color[now];
    for (auto nxt : g[now]) {
        dfs(nxt);
    }
    out[now] = cnt;
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) cin >> color[i + 1];
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    int size = 1;
    while (size < n) size <<= 1;
    size <<= 1;
    for (int i = 1; i <= n; i++)
        st.a[MAXST / 2 + i - 1].push_back(col[i]);
    st.construct();
    int ans = 0;
    for (int i = 0, v, c; i < m; i++) {
        cin >> v >> c;
        ans += st.solve(in[v] - 1, out[v], c, 1, 0, MAXST / 2);
        ans %= MOD;
    }
    cout << ans;
    return 0;
}