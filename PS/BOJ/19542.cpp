#include <bits/stdc++.h>
using namespace std;

int n, s, d;
vector<int> g[100001];
int len[100001];
bool v[100001];
int dfs(int x) {
    v[x] = 1;
    int &ret = len[x];
    for (int nx : g[x]) {
        if(v[nx]) continue;
        ret = max(ret, dfs(nx) + 1);
    }
    return ret;
}
int solve(int x) {
    v[x] = 1;
    int ret = 0;
    for (int nx : g[x]) {
        if(len[nx] < d) continue;
        if(v[nx]) continue;
        ret += solve(nx) + 1;
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> d;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(s);
    memset(v, 0, sizeof(v));
    cout << solve(s) * 2;
    return 0;
}