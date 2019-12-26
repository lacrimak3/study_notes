#include <bits/stdc++.h>
using namespace std;

int n, MIN = 2e9 + 1, MINi, MINj;
int a[100001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        int j = lower_bound(a, a + n, -a[i]) - a;
        for(int k = 0; k < 3; k++){
            int m = j + k - 1;
            if(m < 0 || m >= n || i == m) continue;
            if(abs(a[i] + a[m]) < MIN){
                MIN = abs(a[i] + a[m]);
                MINi = i;
                MINj = m;
            }
        }
    }
    cout << a[MINi] << ' ' << a[MINj];
    return 0;
}