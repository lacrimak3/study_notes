#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int T;
int ans;
int n;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int a[101][101];
bool v[101][101];
void dfs(int x, int y, int k);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 1;
        cin >> n;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        for(int k = 1; k <= 100; k++){
            int comp = 0;
            memset(v, 0, sizeof(v));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(!v[i][j] && a[i][j] > k){
                        comp++;
                        dfs(i, j, k);
                    }
                }
            }
            ans = max(comp, ans);
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}

void dfs(int x, int y, int k){
    v[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(v[nx][ny] || a[nx][ny] <= k) continue;
        dfs(nx, ny, k);
    }
}