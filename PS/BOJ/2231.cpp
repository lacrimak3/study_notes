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
#include <unordered_map>
#include <vector>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n, ans;
int solve(int x);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        if(solve(i)){
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}

int solve(int x){
    int ret = x;
    while(x){
        ret += x % 10;
        x /= 10;
    }
    if(ret != n) ret = 0;
    return ret;
}