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

const int SIZE = 501;
int n, m;
vector<int> a[SIZE * 2], b[SIZE * 2];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0, t; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> t;
            a[i + j].push_back(t);
        }
    for(int i = 0, t; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> t;
            b[i + j].push_back(t);
        }
    bool ok = true;
    for(int i = 0; i < n + m - 1; i++){
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
        if(a[i] != b[i]) ok = false;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}