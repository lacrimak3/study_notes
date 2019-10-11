#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, v;
vector<int> g[1001];
bool visit[1001];
void dfs(int now);
void bfs();
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> v;
    for(int i = 0, x, y; i < m; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 1; i <= n; i++)
        sort(g[i].begin(), g[i].end());
    dfs(v);
    memset(visit, 0, sizeof(visit));
    cout << '\n';
    bfs();
    return 0;
}

void dfs(int now){
    if(visit[now]) return;
    cout << now << ' ';
    visit[now] = true;
    for(int nxt : g[now])
        dfs(nxt);
}

void bfs(){
    queue<int> q;
    q.push(v);
    visit[v] = true;
    cout << v << ' ';
    while(q.size()){
        int now = q.front();
        q.pop();
        for(int nxt : g[now]){
            if(visit[nxt]) continue;
            visit[nxt] = true;
            q.push(nxt);
            cout << nxt << ' ';
        }
    }
}