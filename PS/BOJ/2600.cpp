#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 501;
int b[3];
int k1, k2;
int d[MAX][MAX][2];

int solve(int k1, int k2, int t) {
    if (k1 < 0 || k2 < 0) return -1;
    int &ret = d[k1][k2][t];
    if (k1 == 0 && k2 == 0) return ret = 0;
    if (ret != -1) return ret;
    for (int i = 3; i--;)
        if (!solve(k1 - b[i], k2, 1 - t)) return ret = 1;
    for (int i = 3; i--;)
        if (!solve(k1, k2 - b[i], 1 - t)) return ret = 1;
    return ret = 0;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> b[0] >> b[1] >> b[2];
    for (int ii = 5; ii--;) {
        memset(d, -1, sizeof(d));
        cin >> k1 >> k2;
        if (solve(k1, k2, 0))
            cout << "A\n";
        else
            cout << "B\n";
    }
    return 0;
}