#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int T;
int dx[] = {1, 0};
int dy[] = {0, 1};
int n, m;
string ans;
char a[2001][2001];
bool visit[2001][2001];
queue<pair<int, int>> q;
pair<int, int> bo[2001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        ans = "";
        memset(visit, 0, sizeof(visit));
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        q.push({0, 0});
        visit[0][0] = true;
        while(q.size()){
            ans += a[q.front().first][q.front().second];
            int len = q.size();
            int bo_len = 0;
            char minv = 127;
            while(len--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i = 0; i < 2; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx >= n || ny >= m || visit[nx][ny]) continue;
                    if(minv >= a[nx][ny]){
                        minv = a[nx][ny];
                        bo[bo_len++] = {nx, ny};
                    }
                    visit[nx][ny] = true;
                }
            }
            for(int i = 0; i < bo_len; i++){
                int &x = bo[i].first, &y = bo[i].second;
                if(a[x][y] == minv) q.push({x, y});
            }            
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}