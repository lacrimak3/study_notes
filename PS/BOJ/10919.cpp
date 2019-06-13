#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

const int N = 1e7 + 2;
int n, k, l;
int a[N];
long long d[N], d1[N];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> l;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++){
        int j = max(0, i - k);
        d[i] = d[j] + a[i] + min(a[i], l - a[i]);
    }
    for(int i = n; i; i--){
        int j = min(n + 1, i + k);
        d1[i] = d1[j] + l - a[i] + min(a[i], l - a[i]);
    }    
    long long ans = LINF;
    for(int i = 0; i <= n; i++)
        ans = min(ans, d[i] + d1[i + 1]);
    cout << ans << '\n';
    return 0;
}