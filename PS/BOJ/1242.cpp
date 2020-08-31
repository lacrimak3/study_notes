#include <bits/stdc++.h>
using namespace std;

int n, k, m, ans;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    while (++ans) {
        int tk = k;
        tk %= n;
        if (!tk) tk = n;
        if(tk == m) break;
        m = (m - tk + n) % n;
        n--;
    }
    cout << ans;
    return 0;
}