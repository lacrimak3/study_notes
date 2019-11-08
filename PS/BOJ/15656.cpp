#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[7], ans[7];
void solve(int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        ans[cnt] = a[i];
        solve(cnt + 1);
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    solve(0);
    return 0;
}