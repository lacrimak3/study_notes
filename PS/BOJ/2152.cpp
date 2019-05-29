#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
const int SIZE = 10001;
int N, M, S, T, cnt, SN, tc;
int dfsn[SIZE], sn[SIZE], ind[SIZE], SW[SIZE];
bool fin[SIZE];
vector<int> g[SIZE];
stack<int> st;

int dfs(int now);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--){    
        cin >> N >> M >> S >> T;
        S--;
        T--;
        while(M--){
            int u, v;
            cin >> u >> v;
            g[u - 1].push_back(v - 1);
        }
        for(int i = 0; i < N; ++i)
            if(!dfsn[i]) dfs(i);
        vector<int> SG[SIZE];
        for(int i = 0; i < N; ++i){
            int si = sn[i];
            for(int j : g[i]){
                int sj = sn[j];
                if(si == sj) continue;
                ind[sj]++;
                SG[si].push_back(sj);
            }
        }
        S = sn[S];
        T = sn[T];
        queue<int> Q;
        bool ok[SIZE] = {0};
        int city[SIZE] = {0};
        ok[S] = true;
        for(int i = 0; i < SN; ++i){
            if(!ind[i]) Q.push(i);
        }
        city[S] = SW[S];
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            for(int nxt : SG[now]){
                if(ok[now]){
                    city[nxt] = max(city[nxt], city[now] + SW[nxt]);
                    ok[nxt] = true;
                }
                if(--ind[nxt] == 0) Q.push(nxt);
            }
        }
        cout << city[T];
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
            SW[SN]++;
            if(t == now) break;
        }
        SN++;
    }
    return res;
}