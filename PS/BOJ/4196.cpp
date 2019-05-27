#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int SIZE = 100001;
int v, e, cnt, SN, tc;
int dfsn[SIZE], sn[SIZE];
bool fin[SIZE];
vector<int> g[SIZE];
stack<int> st;
int dfs(int now);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--){
        cnt = SN = 0;
        memset(dfsn, 0, sizeof(dfsn));
        memset(sn, 0, sizeof(sn));
        memset(fin, 0, sizeof(fin));
        cin >> v >> e;
        for(int i = 0; i < v; ++i) g[i].clear();
        while(e--){
            int u, v;
            cin >> u >> v;
            g[u - 1].push_back(v - 1);
        }
        for(int i = 0; i < v; ++i)
            if(!dfsn[i]) dfs(i);
        int indegree[SIZE] = {0};
        for(int i = 0; i < v; ++i){
            for(int j : g[i])
                if(sn[i] != sn[j]) indegree[sn[j]]++;
        }
        int ans = 0;
        for(int i = 0; i < SN; ++i)
            if(indegree[i] == 0) ++ans;
        cout << ans << '\n';
    }
    return 0;
}

int dfs(int now){
    dfsn[now] = ++cnt;
    st.push(now);
    int res = dfsn[now];
    for(int nxt : g[now]){
        if(!dfsn[nxt]) res = min(res, dfs(nxt));
        else if(!fin[nxt]) res = min(res, dfsn[nxt]);
    }
    if(res == dfsn[now]){
        while(1){
            int t = st.top();
            st.pop();
            fin[t] = true;
            sn[t] = SN;
            if(t == now) break;
        }
        SN++;
    }
    return res;
}