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
    int n;
    cin >> n;
    int w = (n + 2) / 2;
    cout << w << '\n';
    for(int i = 1; i <= w; i++)
        cout << 1 << ' ' << i << '\n';
    for(int i = 2; i <= n - w + 1; i++)
        cout << w << ' ' << i << '\n';
    return 0;
}