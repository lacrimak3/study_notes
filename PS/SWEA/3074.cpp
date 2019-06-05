#include <cstring>
#include <iostream>
using namespace std;

int T;
long long ans;
int n, m, a[100001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        long long l = 1, r = 1e18;
        while(l < r){
            long long mid = (l + r) / 2;
            long long sum = 0;
            for(int i = 0; i < n; i++)
                sum += mid / a[i];
            if(sum >= m) r = mid;
            else l = mid + 1;
        }
        ans = r;
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}