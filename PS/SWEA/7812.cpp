#include <cstring>
#include <iostream>
using namespace std;

int T;
int ans;
int a[10001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        int s = 0, e = 0, tmp = a[0];
        if(tmp == m) ans++;
        while(s < n && e < n){
            if(s == e){
                e++;
                if(e == n) break;
                tmp += a[e];
            }
            else if(e < n && tmp < m){
                e++;
                tmp += a[e];
            }
            else{
                tmp -= a[s];
                s++;
            }
            if(tmp == m) ans++;
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}