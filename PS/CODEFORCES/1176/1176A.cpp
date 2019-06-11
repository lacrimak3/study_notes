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

int q;
long long n;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--){
        cin >> n;
        int ans = 0;
        while(n % 2 == 0){
            n /= 2;
            ans++;
        }
        while(n % 3 == 0){
            n /= 3;
            ans += 2;
        }
        while(n % 5 == 0){
            n /= 5;
            ans += 3;
        }
        if(n != 1) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}