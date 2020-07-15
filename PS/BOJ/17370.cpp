#include <bits/stdc++.h>
using namespace std;

int n;
bool a[101][101];
int dx[] = {0, -1, 1};
int dy[] = {1, -1, -1};
int dx2[] = {0, 1, -1};
int dy2[] = {-1, 1, 1};
int ans;
void dfs(int x, int y, int px, int py, int step) {
    if(step == n + 1) {
        if(a[x][y] == 1) ans++;
        return;
    }
    if(a[x][y]) return;
    a[x][y] = 1;
    for(int i = 0; i < 3; i++) {
        int nx, ny;
        if(step % 2 == 0) {
            nx = x + dx[i];
            ny = y + dy[i];
        }
        else {
            nx = x + dx2[i];
            ny = y + dy2[i];
        }
        if(nx == px && ny == py) continue;
        dfs(nx, ny, x, y, step + 1);
    }
    a[x][y] = 0;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int x = 50, y = 50;
    dfs(x, y, -1, -1, 0);
    cout << ans / 3;
    return 0;
}