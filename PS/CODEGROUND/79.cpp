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

const int N = 200001;
int T;
int ans;
int n;
int a[N], b[N];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    int tc = 0;
    while(tc++ < T){
        ans = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int maxv = -1;
        for(int i = 0; i < n; i++){
            if(a[i] == b[i]){
                if(maxv <= b[i]) ans++;
            }
            maxv = max(maxv, a[i]);
        }
        cout << "Case #" << tc << '\n' << ans << '\n';
    }
    return 0;
}