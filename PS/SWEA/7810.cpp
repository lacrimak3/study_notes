#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
 
const int N = 500001;
int T;
int ans;
int a[N];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < n; i++){
            ans = max(ans, min(a[i], n - i));
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}