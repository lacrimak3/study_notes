#include <bits/stdc++.h>
using namespace std;

int n;
long long d[91][2];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1][0] = d[1][1] = 1;
    for(int i = 2; i <= n; i++){
        d[i][0] = d[i - 1][0] + d[i - 1][1];
        d[i][1] = d[i - 1][0];
    }
    cout << d[n][1];
    return 0;
}