#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int T;
int ans;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;
char a[21][21];
int findMax(int x, int y, int bit, int cnt);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        ans = findMax(0, 0, 0, 1);
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}

int findMax(int x, int y, int bit, int cnt){
    if(cnt == 26) return 26;
    int ret = cnt;
    bit |= 1 << (a[x][y] - 'A');
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(bit & 1 << (a[nx][ny] - 'A')) continue;
        ret = max(ret, findMax(nx, ny, bit, cnt + 1));
    }
    return ret;
}