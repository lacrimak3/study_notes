#include <bits/stdc++.h>
using namespace std;


int n;
long long a[5001];
long long ans[4];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ans[0] = 2e18;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            long long t = a[i] + a[j];
            int idx = lower_bound(a, a + n, -t) - a;
            for(int k = idx - 2; k <= idx + 2; k++){
                if(k < 0 || k >= n) continue;
                if(k == i || k == j) continue;
                int v = abs(t + a[k]);
                if(ans[0] > v){
                    ans[0] = v;
                    ans[1] = a[i];
                    ans[2] = a[j];
                    ans[3] = a[k];
                }
            }
        }
    }
    sort(ans + 1, ans + 4);
    for(int i = 1; i < 4; i++) cout << ans[i] << ' ';
    return 0;
}