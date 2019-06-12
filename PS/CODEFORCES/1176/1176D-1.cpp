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

struct comp{
    bool operator() (const int &x, const int &y) const{
    return x > y;
    }
};
const int N = 2750132;
int n;
int p[N], pn[N], a[N];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2; i < N; i++)
        p[i] = i;
    for(int i = 2; i < N; i++){
        if(p[i] != i){
            p[i] = i / p[i];
            continue;
        }
        for(int j = i + i; j < N; j += i){
            p[j] = min(p[j], i);
        }
    }
    int cnt = 1;
    for(int i = 2; i < N; i++){
        if(p[i] == i) pn[i] = cnt++;
    }
    cin >> n;
    for(int i = 0, t; i < 2 * n; i++){
        cin >> t;
        a[t]++;
    }
    vector<int> ans;
    for(int i = N - 1; i >= 0; i--){
        while(a[i] > 0){
            if(p[i] == i){
                a[pn[i]]--;
                ans.push_back(pn[i]);
            }
            else{
                a[p[i]]--;
                ans.push_back(i);
            }
            a[i]--;
        }
    }
    
    for(auto it : ans)
        cout << it << ' ';
    return 0;
}