#include <cstring>
#include <iostream>
using namespace std;

const int N = 1000001;
int T;
int ans;
int a[N];
bool check(int n, int h, int m);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) cin >> a[i];
        int l = 0, r = 1e9;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(check(n, mid, m)) l = mid;
            else r = mid - 1;
        }
        ans = r;
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}

bool check(int n, int h, int m){
    long long res = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > h) res += a[i] - h;
    }
    return res >= m;
}