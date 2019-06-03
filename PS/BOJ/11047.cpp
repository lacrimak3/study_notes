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
    int N, K;
    int a[11];
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> a[i];
    N--;
    int ans = 0;
    while(K){
        if(a[N] <= K){
            ans += K / a[N];
            K %= a[N];
        }
        N--;
    }
    cout << ans << '\n';
    return 0;
}