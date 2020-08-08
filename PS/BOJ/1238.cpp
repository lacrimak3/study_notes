#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9 + 7;
int n, m, q;
vector<pair<int, int>> g[1001];
int ans[1001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for (int i = 0, u, v, t; i < m; i++) {
        cin >> u >> v >> t;
        g[u].push_back({v, t});
    }
    for(int i = 1; i <= n; i++) {
        int dist[1001];
        fill(dist, dist + 1001, MAX);
        priority_queue<pair<int, int>> pq;
        pq.push({0, i});
        dist[i] = 0;
        bool flag = true;
        while(pq.size() && flag) {
            int x = pq.top().second, t = -pq.top().first;
            pq.pop();
            for(auto &[nx, nt] : g[x]) {
                if(t + nt < dist[nx]) {
                    dist[nx] = t + nt;
                    pq.push({-dist[nx], nx});
                }
            }
        }
        if(i == q)
            for(int j = 1; j <= n; j++) ans[j] += dist[j];
        else ans[i] += dist[q];
    }
    int maxv = -1;
    for(int i = 1; i <= n; i++) maxv = max(maxv, ans[i]);
    cout << maxv;
    return 0;
}