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
const int MOD = 998244353;

const int SIZE = 200001;
int n;
long long f[SIZE];
vector<vector<int>> tr;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    f[1] = 1;
    for(int i = 2; i < SIZE; i++){
        f[i] = (f[i - 1] * i) % MOD;
    }
    tr.resize(n + 1);
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    long long ans = 1;
    for(int i = 1; i <= n; i++){
        ans = (ans * f[tr[i].size()]) % MOD;
    }
    ans = (ans * n) % MOD;
    cout << ans << '\n';
    return 0;
}