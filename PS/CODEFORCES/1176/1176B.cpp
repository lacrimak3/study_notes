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

const int SIZE = 101;
int q;
int n;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> q;
    while(q--){
        cin >> n;
        vector<int> a;
        int ans = 0, one = 0, two = 0;
        for(int i = 0, x; i < n; i++){
            cin >> x;
            x %= 3;
            if(x == 0) ans++;
            else if(x == 1) one++;
            else if(x == 2) two++;
        }
        int mv = min(one, two);
        ans += mv;
        one -= mv;
        two -= mv;
        if(one > 0) ans += one / 3;
        if(two > 0) ans += two / 3;     
        cout << ans << '\n';
    }
    return 0;
}