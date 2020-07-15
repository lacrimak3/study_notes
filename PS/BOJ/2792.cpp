#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[300001];
bool check(int v) {
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        cnt += a[i] / v;
        if(a[i] % v) cnt++;
    }
    return cnt <= n;
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    long long l = 1, r = 1e9;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r;
    return 0;
}