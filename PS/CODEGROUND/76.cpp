#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 200001;

int T;
int ans;
int n, m;
vector<int> g[N];
int _size[N];
bool act[N];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) g[i].clear();
        for(int i = 0, u, v; i < m; i++){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(g[i].size()){
                sort(g[i].begin(), g[i].end());
                if(g[i].size() == 2) q.push(i);
            }
            act[i] = true;
            _size[i] = g[i].size();
        }
        while(q.size()){
            int now = q.front();
            q.pop();
            if(_size[now] != 2) continue;
            int t[2];
            int j = 0;
            for(int i : g[now]){
                if(act[i]) t[j++] = i;
            }
            if(binary_search(g[t[0]].begin(), g[t[0]].end(), t[1])){
                act[now] = false;
                _size[t[0]]--;
                _size[t[1]]--;
                if(_size[t[0]] == 2) q.push(t[0]);
                if(_size[t[1]] == 2) q.push(t[1]);
            }
        }
        for(int i = 1; i <= n; i++) if(act[i]) ans++;
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}