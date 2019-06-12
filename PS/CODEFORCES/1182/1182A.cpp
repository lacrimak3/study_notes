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
int d[61];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n % 2) cout << 0;
    else{
        int ans = 1;
        for(int i = 0; i < n / 2; i++)
            ans *= 2;
        cout << ans;
    }
    return 0;
}