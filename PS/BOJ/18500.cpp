#include <bits/stdc++.h>
using namespace std;

const int MAX = 987654321;
int r, c, n;
char m[101][101];
int v[101][101];
int vt;
bool lr;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void moveCluster() {
    vector<pair<int, int>> cluster;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == vt) cluster.push_back({i, j});
        }
    }
    int minDist = MAX;
    for (int i = 0; i < cluster.size(); i++) {
        int x = cluster[i].first, y = cluster[i].second;
        int cnt = 0;
        for (int j = x + 1; j < r; j++, cnt++) {
            if (m[j][y] == 'x' && v[j][y] != vt) break;
        }
        minDist = min(minDist, cnt);
        m[x][y] = '.';
    }
    for (int i = 0; i < cluster.size(); i++) {
        int x = cluster[i].first + minDist, y = cluster[i].second;
        m[x][y] = 'x';
    }
}

int dfs(int x, int y) {
    if (x < 0 || x >= r || y < 0 || y >= c) return -1;
    if (v[x][y] == vt || m[x][y] == '.') return -1;
    v[x][y] = vt;
    int ret = x;
    for (int i = 0; i < 4; i++) {
        ret = max(ret, dfs(x + dx[i], y + dy[i]));
    }
    return ret;
}

void removeMineral(int x, bool lr) {
    int i = r - x, j;
    if (!lr) {
        for (j = 0; j < c; j++) {
            if (m[i][j] == 'x') {
                m[i][j] = '.';
                break;
            }
        }
        if (j == c) return;
    } else {
        for (j = c - 1; j >= 0; j--) {
            if (m[i][j] == 'x') {
                m[i][j] = '.';
                break;
            }
        }
        if (j == -1) return;
    }
    for (int k = 0; k < 4; k++) {
        vt++;
        int nx = i + dx[k], ny = j + dy[k];
        if (v[nx][ny] >= vt - k && v[nx][ny] < vt) continue;
        int t = dfs(nx, ny);
        if (t != -1 && t < r - 1) {
            moveCluster();
            return;
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for (int i = 0; i < r; i++) cin >> m[i];
    cin >> n;
    for (int i = 0, t; i < n; i++, lr = !lr) {
        cin >> t;
        removeMineral(t, lr);
    }
    for (int i = 0; i < r; i++) cout << m[i] << "\n";
    return 0;
}