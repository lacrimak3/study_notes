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
using ll = long long;
const int N = 200001;
int n, k;
int a[N];
int ans;
vector<pair<ll, ll>> op;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    op.reserve(n);
    for(int i = n / 2; i < n; i++){
        if(i == n / 2 || a[i] != a[i - 1]){
            op.emplace_back(a[i], 1);
        }
        else op.back().second++;
    }
    for(int i = 0; i < op.size(); i++){
        if(i + 1 == op.size()){
            ans = op[i].first + k / op[i].second;
        }
        else{
            if(k < (op[i + 1].first - op[i].first) * op[i].second){
                ans = op[i].first + k / op[i].second;
                break;
            }
            k -= (op[i + 1].first - op[i].first) * op[i].second;
            op[i + 1].second += op[i].second;
        }
    }
    cout << ans;
    return 0;
}