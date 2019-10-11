#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int n, m;
char mp[1001][1001];
bool v[1001][1001];
queue<pair<int, int>> ji, f;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> mp[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mp[i][j] == 'F') f.push({i, j});
            if(mp[i][j] == 'J'){
            	ji.push({i, j});
            	v[i][j] = true;
            }
        }
    }
    int ans = 0;
    bool ok = false;
    while(!ok && ji.size()){
        int len = f.size();
        while(len--){
            int x = f.front().first, y = f.front().second;
            f.pop();
            mp[x][y] = '#';
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(mp[nx][ny] != '.' && mp[nx][ny] != 'J') continue;
                mp[nx][ny] = 'F';
                f.push({nx, ny});
            }
        }
        len = ji.size();
        while(len-- && !ok){
            int x = ji.front().first, y = ji.front().second;
            ji.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                    ok = true;
                    break;
                }
                if(mp[nx][ny] != '.' || v[nx][ny]) continue;
                v[nx][ny] = true;
                ji.push({nx, ny});
            }
        }
        ans++;
    }
    if(ok) cout << ans;
    else cout << "IMPOSSIBLE";
    return 0;
}