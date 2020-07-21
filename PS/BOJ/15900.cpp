#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[500001];
bool v[500001];
int ans;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0, u, v; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    v[1] = true;
    while (q.size()) {
        int now = q.front().first;
        int lv = q.front().second;
        q.pop();
        bool flag = false;
        for (int i = 0; i < g[now].size(); i++) {
            int nxt = g[now][i];
            if(v[nxt]) continue;
            flag = true;
            q.push({nxt, lv + 1});
            v[nxt] = true;
        }
        if(!flag) ans = (ans + lv) % 2;
    }
    if(ans) cout << "Yes";
    else cout << "No";
    return 0;
}