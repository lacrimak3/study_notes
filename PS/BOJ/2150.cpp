#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int SIZE = 10001;
int v, e, cnt, SN;
int dfsn[SIZE], sn[SIZE];
bool fin[SIZE];
vector<int> g[SIZE];
stack<int> st;

vector<vector<int>> scc;
int dfs(int now);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    while(e--){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back(v - 1);
    }
    for(int i = 0; i < v; ++i)
        if(!dfsn[i]) dfs(i);
    sort(scc.begin(), scc.end());
    cout << SN << '\n';
    for(auto &cur_scc : scc){
        for(int cur: cur_scc)
            cout << cur + 1 << ' ';
        cout << "-1\n";
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
        sort(cur_scc.begin(), cur_scc.end());
        scc.push_back(cur_scc);
        SN++;
    }
    return res;
}