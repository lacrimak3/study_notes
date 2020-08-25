#include <bits/stdc++.h>
using namespace std;

struct node {
    int x, mask, cnt;
};

int n, m, k;
int j[101];
int d[101][1 << 15];
bool v[101][1 << 15];
vector<pair<int, int>> g[101];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;

    for (int i = 0, t, x = 0; i < k; i++) {
        cin >> t;
        j[t] = ++x;
    }

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    queue<node> q;
    v[1][0] = 1;
    q.push({1, 0, 0});
    while (q.size()) {
        auto [x, mask, cnt] = q.front();
        q.pop();
        for (auto &[nx, c] : g[x]) {
            if (v[nx][mask] || c < cnt) continue;
            v[nx][mask] = 1;
            d[nx][mask] = cnt;
            q.push({nx, mask, cnt});
        }

        if (j[x] && !(mask & (1 << (j[x] - 1)))) {
            mask |= 1 << (j[x] - 1);
            cnt += 1;
            d[x][mask] = cnt;
            for (auto &[nx, c] : g[x]) {
                if (v[nx][mask] || c < cnt) continue;
                v[nx][mask] = 1;
                d[nx][mask] = cnt;
                q.push({nx, mask, cnt});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 1 << k; i++) ans = max(ans, d[1][i]);
    cout << ans;
    return 0;
}