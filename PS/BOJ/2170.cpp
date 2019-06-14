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

int n;
pair<int, int> a[1000001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    int s = -INF, e = -INF, ans = 0;
    for(int i = 0; i < n; i++){
        if(e < a[i].first){
            ans += e - s;
            s = a[i].first;
        }
        if(e < a[i].second) e = a[i].second;
    }
    ans += e - s;
    cout << ans << '\n';
    return 0;
}