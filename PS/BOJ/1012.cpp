#include <cstring>
#include <iostream>
using namespace std;

int T, ans;
int n, m, k;
int bachu[51][51];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
void dfs(int x, int y);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        memset(bachu, 0, sizeof(bachu));
        ans = 0;
        cin >> m >> n >> k;
        for(int i = 0, x, y; i < k; i++){
            cin >> y >> x;
            bachu[x][y] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(bachu[i][j] == 1){
                    dfs(i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

void dfs(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return;
    if(bachu[x][y] != 1) return;
    bachu[x][y] = 2;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        dfs(nx, ny);
    }
}