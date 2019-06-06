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

int T;
int n, k;
int a[200001];
int d[200001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int as = 0, ae = k, minv = a[n - 1];
        int s = 0, e = k;
        for(int i = 0; i < n - k; i++, s++, e++){
            if(minv > a[e] - a[s]){
                as = s;
                ae = e;
                minv = a[e] - a[s];
            }
        }
        cout << (a[ae] + a[as]) / 2 << '\n';
    }
    return 0;
}