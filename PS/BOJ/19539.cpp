#include <bits/stdc++.h>
using namespace std;

int n;
int m2, n2, sum;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        m2 += t % 2;
        n2 += t / 2;
        sum += t;
    }
    if(!(sum % 3) && m2 <= n2) cout << "YES";
    else cout << "NO";
    return 0;
}