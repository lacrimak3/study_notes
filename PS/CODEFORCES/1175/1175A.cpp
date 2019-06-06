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

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        long long n, k;
        cin >> n >> k;
        long long ans = 0;
        while(n){
            if(n % k != 0){
                ans += (n - n / k * k);
                n = n / k * k;
            }
            if(n != 0){
                n = n / k;
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}