#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int SIZE = 5001;
int n, m, cnt, SN;
int dfsn[SIZE], sn[SIZE], out[SIZE];
bool fin[SIZE];
vector<int> g[SIZE];
stack<int> st;

int dfs(int now);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cnt = SN = 0;
        memset(out, 0, sizeof(out));
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
            g[u - 1].push_back(v - 1);
        }
        for(int i = 0; i < n; ++i)
            if(!dfsn[i]) dfs(i);
        for(int i = 0; i < n; ++i){
            int si = sn[i];
            for(int j : g[i]){
                int sj = sn[j];
                if(si == sj) continue;
                out[si]++;
            }
        }
        for(int i = 0; i < n; ++i){
            if(!out[sn[i]]) cout << i + 1 << ' ';
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