#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int sx, sy, hx, hy, cx, cy;
int n, t;
int g[401][401];
int d[201][401][401];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> sx >> sy >> t >> hx >> hy;
    cx = 200 - sx;
    cy = 200 - sy;
    sx = sy = 200;
    hx += cx;
    hy += cy;
    if(hx < 0 || hy < 0 || hx > 400 || hy > 400) {
        cout << 0;
        return 0;
    }
    cin >> n;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        x += cx;
        y += cy;
        if (x < 0 || y < 0 || x > 400 || y > 400) continue;
        g[x][y] = 1;
    }
    d[0][sx][sy] = 1;
    for (int i = 1; i <= t; i++) {
        for (int j = 0; j <= 400; j++) {
            for (int k = 0; k <= 400; k++) {
                if(g[j][k]) continue;
                for (int ii = 0; ii < 4; ii++) {
                    int nx = j + dx[ii], ny = k + dy[ii];
                    if(nx < 0 || ny < 0 || nx > 400 || ny > 400) continue;
                    if(nx == hx && ny == hy) continue;
                    d[i][j][k] += d[i - 1][nx][ny];
                    d[i][j][k] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= t; i++) {
        ans += d[i][hx][hy];
        ans %= MOD;
    }
    cout << ans;
    return 0;
}