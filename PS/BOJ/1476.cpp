#include <bits/stdc++.h>
using namespace std;

const int E = 15, S = 28, M = 19;
int e, s, m, a, b, c;
int ans;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> e >> s >> m;
    while(a != e || b != s || c != m){
        a = a % E + 1;
        b = b % S + 1;
        c = c % M + 1;
        ans++;
    }
    cout << ans;
    return 0;
}