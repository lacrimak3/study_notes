#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int T;
int n, m;
int dep[200001];
vector<vector<int>> g;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> m;
        g.clear();
        g.resize(n + 1);
        for(int i = 1; i <= n; i++) dep[i] = 0;
        for(int i = 0, u, v; i < m; i++){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        queue<int> q;
        q.push(1);
        dep[1] = 1;
        vector<int> e, o;
        o.push_back(1);
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int nxt : g[now]){
                if(!dep[nxt]){
                    q.push(nxt);
                    dep[nxt] = dep[now] + 1;
                    if(dep[nxt] % 2) o.push_back(nxt);
                    else e.push_back(nxt);
                }
            }
        }
        if(e.size() <= o.size()){
            cout << e.size() << '\n';
            for(int i : e)
                cout << i << ' ';
        }
        else{
            cout << o.size() << '\n';
            for(int i : o)
                cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}