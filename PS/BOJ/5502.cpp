#include <bits/stdc++.h>
using namespace std;

const int MAX = 987654321;
int n;
string s;
int d[5001][5001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < s.length() - 1; i++)
        if (s[i] != s[i + 1]) d[i][i + 1] = 1;
    for (int i = 3; i <= s.length(); i++) {
        for (int j = 0; j < s.length() - i + 1; j++) {
            int x = j, y = j + i - 1;
            d[x][y] = MAX;
            if (s[x] == s[y])
                d[x][y] = d[x + 1][y - 1];
            d[x][y] = min(d[x][y], min(d[x][y - 1] + 1, d[x + 1][y] + 1));
        }
    }
    cout << d[0][n - 1];
    return 0;
}