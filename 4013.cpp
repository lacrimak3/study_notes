#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int SIZE = 50001;
int n, m, cnt, SN, s, p;
int dfsn[SIZE], sn[SIZE], pr[SIZE], spr[SIZE], ind[SIZE];
bool fin[SIZE], re[SIZE], sre[SIZE];
vector<int> g[SIZE], sg[SIZE];
stack<int> st;

int dfs(int now);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }
    for (int i = 0; i < n; ++i) cin >> pr[i];
    cin >> s >> p;
    for (int i = 0; i < p; ++i) {
        int t;
        cin >> t;
        re[t - 1] = true;
    }
    for (int i = 0; i < n; ++i)
        if (!dfsn[i]) dfs(i);

    int sStart = -1;
    for (int i = 0; i < n; ++i) {
        int si = sn[i];
        if (i == s) sStart = si;
        for (int j : g[i]) {
            int sj = sn[j];
            if (si == sj) continue;
            sg[si].push_back(sj);
            ind[sj]++;
        }
    }
    queue<int> q;
    int sMax[SIZE];
    bool sCal[SIZE] = {0};
    sCal[sStart] = true;
    for (int i = 0; i < SN; ++i) {
        sMax[i] = spr[i];
        if(ind[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int nxt : sg[now]){
            if(sCal[now]){
                sMax[nxt] = max(sMax[nxt], sMax[now] + spr[nxt]);
                sCal[nxt] = true;
            }
            if(--ind[nxt] == 0) q.push(nxt);
        }
    }
    int ans = 0;
    for(int i = 0; i < SN; ++i){
        if(sre[i] && sCal[i]) ans = max(ans, sMax[i]);
    }
    cout << ans;
    return 0;
}

int dfs(int now) {
    dfsn[now] = ++cnt;
    st.push(now);

    int res = dfsn[now];
    for (int nxt : g[now]) {
        if (!dfsn[nxt])
            res = min(res, dfs(nxt));
        else if (!fin[nxt])
            res = min(res, dfsn[nxt]);
    }
    if (res == dfsn[now]) {
        while (1) {
            int t = st.top();
            st.pop();
            fin[t] = true;
            sn[t] = SN;
            sre[SN] |= re[t];
            spr[SN] += pr[t];
            if (t == now) break;
        }
        SN++;
    }
    return res;
}