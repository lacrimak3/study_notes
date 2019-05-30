#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
const int SIZE = 301;
int N, M, cnt, SN, tc;
int dfsn[SIZE], sn[SIZE], sg[SIZE][SIZE];
bool fin[SIZE];
vector<int> g[SIZE];
vector<vector<int>> scc;
stack<int> st;

int dfs(int now);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--){
        cnt = SN = 0;
        memset(sg, 0, sizeof(sg));
        memset(dfsn, 0, sizeof(dfsn));
        memset(sn, 0, sizeof(sn));
        memset(fin, 0, sizeof(fin));
        cin >> N;
        for(int i = 0; i < scc.size(); i++)
            scc[i].clear();
        scc.clear();
        for(int i = 0; i < N; i++){
            g[i].clear();
            string s;
            cin >> s;
            for(int j = 0; j < N; j++)
                if(s[j] == '1') g[i].push_back(j);
        }
        vector<pair<int, int>> ans;
        for(int i = 0; i < N; i++)
            if(!dfsn[i]) dfs(i);
        for(int i = 0; i < N; i++){
            int si = sn[i];
            for(int j : g[i]){
                int sj = sn[j];
                if(si == sj) continue;
                sg[si][sj] = 1;
            }
        }
        for(int i = 0; i < SN; i++){
            for(int j = 0; j < scc[i].size() && scc[i].size() != 1; j++){
                if(j == scc[i].size() - 1)
                    ans.push_back({scc[i][j], scc[i][0]});
                else
                    ans.push_back({scc[i][j], scc[i][j + 1]});
            }
        }
        for(int k = 0; k < SN; k++){
            for(int i = 0; i < SN; i++){
                for(int j = 0; j < SN; j++){
                    if(sg[i][j] && sg[i][k] && sg[k][j]) sg[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < SN; i++)
            for(int j = 0; j < SN; j++){
                if(sg[i][j]) ans.push_back({scc[i][0], scc[j][0]});
            }
        cout << ans.size() << '\n';
        for(auto i : ans){
            cout << i.first + 1 << ' ' << i.second + 1 << '\n';
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
        vector<int> cur_scc;
        while(1){
            int t = st.top();
            st.pop();
            cur_scc.push_back(t);
            fin[t] = true;
            sn[t] = SN;
            if(t == now) break;
        }
        scc.push_back(cur_scc);
        SN++;
    }
    return res;
}