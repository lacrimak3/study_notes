#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int SIZE = 1001;
int T;
int ans;
int n, m;
int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
int dy[] = {-1, 1, 0, -1, 1, 0, -1, 1};
int a[SIZE][SIZE];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        cin >> n >> m;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < m; j++){
                if(s[j] == '.') q.push({i, j});
                else a[i][j] = s[j] - '0';
            }
        }
        while(!q.empty()){
            int len = q.size();
            bool ok = false;
            while(len--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(int i = 0; i < 8; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    a[nx][ny]--;
                    if(a[nx][ny] == 0){
                        q.push({nx, ny});
                        ok = true;
                    }
                }
            }
            if(ok) ans++;
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}