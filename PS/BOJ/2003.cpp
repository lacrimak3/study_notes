#include <bits/stdc++.h>
using namespace std;

int n, m, s, e, sum, ans;
int a[10001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sum = a[0];
    while(e < n){
        if(sum < m) sum += a[++e];
        else if(sum == m){
            ans++;
            sum += a[++e];
        }
        else{
            if(s == e) sum += a[++e];
            else sum -= a[s++];
        }
    }
    cout << ans;
    return 0;
}