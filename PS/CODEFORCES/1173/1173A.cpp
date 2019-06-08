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
    int x, y, z;
    cin >> x >> y >> z;
    char ans;
    if(abs(x - y) <= z && z != 0) ans = '?';
    else if(x == y) ans = '0';
    else if(x > y) ans = '+';
    else ans = '-';
    cout << ans << '\n';
    return 0;
}