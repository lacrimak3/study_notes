#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>

using namespace std;
const int SIZE = 101;
int N, V, SN, cnt;
int dfsn[SIZE], sn[SIZE], ind[SIZE], ind2[SIZE];
bool fin[SIZE];
vector<int> adj[SIZE], sadj[SIZE];
stack<int> st;
vector<vector<int>> scc;
unordered_map<string, int> word;
unordered_map<int, string> rword;
int GetScc(int now);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        V = SN = cnt = 0;
        fill(dfsn, dfsn + SIZE, 0);
        fill(sn, sn + SIZE, 0);
        fill(ind, ind + SIZE, 0);
        fill(ind2, ind2 + SIZE, 0);
        fill(fin, fin + SIZE, 0);
        for(int i = 0; i < SIZE; i++){
            adj[i].clear();
            sadj[i].clear();
        }
        word.clear();
        rword.clear();
        scc.clear();
        cin >> N;
        if(N == 0) break;
        string t;
        getline(cin, t);
        for(int i = 0; i < N; i++){
            string s, t;
            int u, v;
            getline(cin, s);
            stringstream ss(s);
            ss >> t;
            if(word.count(t) == 0)
                word[t] = V++;
            u = word[t];
            if(rword.count(u) == 0)
                rword[u] = t;
            while(ss >> t){
                if(word.count(t) == 0)
                    word[t] = V++;
                v = word[t];
                if(rword.count(v) == 0)
                    rword[v] = t;
                adj[v].push_back(u);
            }
        }
        for(int i = 0; i < V; i++)
            if(!dfsn[i]) GetScc(i);
        for(int i = 0; i < V; i++){
            int si = sn[i];
            for(int j : adj[i]){
                int sj = sn[j];
                if(si == sj) continue;
                ind[si]++;
                ind2[sj]++;
                sadj[sj].push_back(si);
            }
        }
        queue<int> Q;
        bool chk[SIZE] = {0};
        for(int i = 0; i < SN; i++)
            if(ind[i] == 0){
                Q.push(i);
                if(scc[i].size() > 1) chk[i] = true;
            }
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            for(int nxt : sadj[now]){
                chk[nxt] |= chk[now];
                if(scc[nxt].size() > 1) chk[nxt] = true;
                if(--ind[nxt] == 0) Q.push(nxt);
            }
        }
        for(int i = 0; i < SN; i++)
            if(ind2[i] == 0) chk[i] = true;
        int cnt = 0;
        vector<string> ans;
        for(int i = 0; i < SN; i++){
            if(chk[i]){
                for(int j : scc[i])
                    ans.push_back(rword[j]);
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        for(string &s : ans)
            cout << s << ' ';
        cout << '\n';
    }
    return 0;
}

int GetScc(int now){
    dfsn[now] = ++cnt;
    st.push(now);
    int res = dfsn[now];
    for(int nxt : adj[now]){
        if(!dfsn[nxt]) res = min(res, GetScc(nxt));
        else if(!fin[nxt]) res = min(res, dfsn[nxt]);
    }
    if(res == dfsn[now]){
        vector<int> cur_scc;
        while(!st.empty()){
            int t = st.top();
            st.pop();
            fin[t] = true;
            cur_scc.push_back(t);
            sn[t] = SN;
            if(t == now) break;
        }
        scc.push_back(cur_scc);
        SN++;
    }   
    return res;
}