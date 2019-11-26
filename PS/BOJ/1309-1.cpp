#include <bits/stdc++.h>
using namespace std;

int n;
int d[100001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[0] = 1;
    d[1] = 3;
    for(int i = 2; i <= n; i++)
        d[i] = (d[i - 1] * 2 + d[i - 2]) % 9901;
    cout << d[n];
    return 0;
}