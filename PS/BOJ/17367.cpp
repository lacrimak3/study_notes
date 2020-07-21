#include <bits/stdc++.h>
using namespace std;

int n;
double d[1001][7][7][7];

double calc(int x, int y, int z) {
    if (x == y && y == z) {
        return 10000 + x * 1000;
    } else if (x == y || y == z || x == z) {
        if (x == y) {
            return 1000 + x * 100;
        } else {
            return 1000 + z * 100;
        }
    } else {
        return max(max(x, y), z) * 100;
    }
}

double solve(int l, int x, int y, int z) {
    double &ret = d[l][x][y][z];
    if (!(ret < 0)) return ret;
    ret = calc(x, y, z);
    if (l == 0) return ret;
    double tmp = 0;
    for (int i = 1; i <= 6; i++)
        tmp += solve(l - 1, y, z, i);
    return ret = max(ret, tmp / 6);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 7; k++) {
                for (int x = 0; x < 7; x++) {
                    d[i][j][k][x] = -1;
                }
            }
        }
    }
    cin >> n;
    double ans = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            for (int k = 1; k <= 6; k++) {
                ans += solve(n - 3, i, j, k);
            }
        }
    }
    cout << fixed;
    cout.precision(10);
    cout << ans / (6 * 6 * 6);
    return 0;
}