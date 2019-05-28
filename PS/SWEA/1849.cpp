#include <cstring>
#include <iostream>
using namespace std;

const int SIZE = 100001;
int T;
int n, m;
int p[SIZE], g[SIZE], r[SIZE];
void Union(int u, int v, int w);
int Find(int u);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << '#' << tc << ' ';
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            p[i] = i;
            g[i] = r[i] = 0;
        }
        while (m--) {
            char c;
            cin >> c;
            if (c == '!') {
                int u, v, w;
                cin >> u >> v >> w;
                Union(u, v, w);
            } else {
                int u, v;
                cin >> u >> v;
                int pu = Find(u);
                int pv = Find(v);
                if (pu != pv)
                    cout << "UNKNOWN ";
                else
                    cout << g[v] - g[u] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}

void Union(int u, int v, int w) {
    w += g[u] - g[v];
    u = Find(u);
    v = Find(v);
    if (u == v) return;
    if (r[u] > r[v]) {
        p[v] = u;
        g[v] += w;
    } else {
        p[u] = v;
        g[u] -= w;
    }
    if (r[u] == r[v]) r[v]++;
}

int Find(int u) {
    if (u == p[u]) return u;
    g[u] += g[p[u]];
    return p[u] = Find(p[u]);
}