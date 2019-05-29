#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int SIZE = 100001;
int n, m, cnt, SN, tc;
int dfsn[SIZE], sn[SIZE], ind[SIZE];
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
        memset(ind, 0, sizeof(ind));
        memset(dfsn, 0, sizeof(dfsn));
        memset(fin, 0, sizeof(fin));
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; ++i){
            g[i].clear();
        }
        cin >> m;
        while(m--){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        for(int i = 0; i < n; ++i)
            if(!dfsn[i]) dfs(i);
        for(int i = 0; i < n; ++i){
            int si = sn[i];
            for(int j : g[i]){
                int sj = sn[j];
                if(si == sj) continue;
                ind[sj]++;
            }
        }
        int Scnt = 0;
        for(int i = 0; i < SN; ++i){
            if(!ind[i]) Scnt++;
        }
        if(Scnt != 1){
            cout << "Confused\n";
        }
        else{
            for(int i = 0; i < n; ++i){
                if(!ind[sn[i]]) cout << i << '\n';
            }
        }
        cout << '\n';
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