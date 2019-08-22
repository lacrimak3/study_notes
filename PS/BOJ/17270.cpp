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
const int N = 101;
const int INF = 1e9 + 7;

int dist1[N], dist2[N];
int V, M, J, S;
vector<pair<int, int>> g[N];
void dijkstra(int s, int dist[N]){
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(pq.size()){
        auto [ncost, now] = pq.top();
        pq.pop();
        for(auto [nxt, cost] : g[now]){
            if(dist[nxt] > -ncost + cost){
                dist[nxt] = -ncost + cost;
                pq.push({-dist[nxt], nxt});
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> M;
    for(int i = 1; i <= V; i++)
        dist1[i] = dist2[i] = INF;

    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    cin >> J >> S;
    dijkstra(J, dist1);
    dijkstra(S, dist2);
    int ans = -1, short_path = INF;
    for(int i = 1; i <= V; i++){
        if(i == J || i == S) continue;
        if(dist1[i] == INF || dist2[i] == INF) continue;
        short_path = min(short_path, dist1[i] + dist2[i]);
    }
    for(int i = 1; i <= V; i++){
        if(i == J || i == S) continue;
        if(dist1[i] == INF || dist2[i] == INF) continue;
        if(dist1[i] + dist2[i] != short_path) continue;
        if(dist1[i] > dist2[i]) continue;
        if(ans == -1) ans = i;
        else if(dist1[i] < dist1[ans]) ans = i;
    }
    cout << ans;
    return 0;
}