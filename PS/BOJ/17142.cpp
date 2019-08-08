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
const int INF = 987654321;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n, m;
int emp, ans = INF;
int a[51][51];
int visit[51][51], vc;
vector<pair<int, int>> vi;
vector<pair<int, int>> act;
void dfs(int idx, int cnt){
    if(cnt == m){
        queue<pair<int, int>> q;
        int empNow = emp;
        for(int i = 0; i < m; i++){
            q.push(act[i]);
            visit[act[i].first][act[i].second] = vc;
        }
        int time = 0;
        while(q.size()){
            int len = q.size();
            bool ok = false;
            if(!empNow) break;
            while(len--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(a[nx][ny] != 1 && a[nx][ny] < vc && visit[nx][ny] < vc){
                        ok = true;
                        if(a[nx][ny] == 0){
                            empNow--;
                            if(!empNow) break;
                        }
                        visit[nx][ny] = vc;
                        q.push({nx, ny});
                    }
                }
                if(!empNow) break;
            }
            if(ok) time++;
        }
        if(!empNow){
            ans = min(ans, time);
        }
        vc++;
        return;
    }
    for(int i = idx; i < vi.size(); i++){
        act.push_back(vi[i]);
        dfs(i + 1, cnt + 1);
        act.pop_back();
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vi.reserve(n * n + 1);
    vc = 3;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(a[i][j] == 2) vi.push_back({i, j});
            else if(a[i][j] == 0) emp++;
        }
    }
    dfs(0, 0);
    if(ans == INF) ans = -1;
    cout << ans;
    return 0;
}