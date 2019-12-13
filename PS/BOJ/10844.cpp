#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000;

int n;
int d[101][10];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < 10; i++) d[1][i] = 1;
    for(int i = 2; i <= n; i++){
        d[i][0] = d[i - 1][1];
        d[i][9] = d[i - 1][8];
        for(int j = 1; j <= 8; j++) d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % MOD;
    }
    int ans = 0;
    for(int i = 0; i < 10; i++) ans = (ans + d[n][i]) % MOD;
    cout << ans;
    return 0;
}