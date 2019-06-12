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
int p[N];
int pn[N];
multiset<int, comp> a;
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
    for(int i = 0, t; i < n * 2; i++){
        cin >> t;
        a.insert(t);
    }
    vector<int> ans;
    while(!a.empty()){
        auto it = a.begin();
        int x = *it, y = p[x];
        if(p[x] == x) y = pn[x];
        auto it2 = a.find(y);
        a.erase(it2);
        a.erase(it);
        if(p[x] == x) ans.push_back(y);
        else ans.push_back(x);
    }
    for(auto it : ans)
        cout << it << ' ';
    return 0;
}