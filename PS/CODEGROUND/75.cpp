#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int T;
int ans;
int n, k;
int a[200001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for(int i = 0, j = 0; i < n; i++){
            while(j < n && a[j] <= a[i] + k) j++;
            ans = max(ans, j - i);
        }
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}