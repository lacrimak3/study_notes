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

const int SIZE = 200001;
int n;
int a[SIZE], p[SIZE];
int chk();
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int ans = -1;
    for(int i = 1; i <= n; i++) cin >> a[i];
    bool zero = false, ok = true;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[a[i]] = i;
    }
    for(int i = 1; i <= n; i++)
        ans = max(ans, p[i] - i + n + 1);
    ans = min(ans, chk());
    cout << ans << '\n';
    return 0;
}

int chk(){
    int ret = INF;
    int one = n;
    for(int i = n - 1; i >= 0; i--)
        if(a[i] != 0 && a[i] == a[i + 1] - 1) one = i;
    if(a[one] != 1) return ret;
    

    return ret;
}