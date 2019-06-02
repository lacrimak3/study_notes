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

int N, S;
int a[20];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> S;
    int ans = 0;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 1; i < (1 << N); i++){
        int sum = 0;
        for(int j = 0; j < N; j++)
            if((1 << j) & i){
                sum += a[j];
            }
        if(sum == S) ans++;
    }
    cout << ans << '\n';
    return 0;
}