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

int n;
vector<pair<char, int>> w[1000001];
vector<string> a;
vector<pair<int, int>> c;
queue<pair<int, int>> b, d;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        char c = 0;
        int vowel = 0;
        for(int j = 0; j < a[i].size(); j++){
            if(a[i][j] == 'a' || a[i][j] == 'e' || a[i][j] == 'i' || a[i][j] == 'o' || a[i][j] == 'u'){
                vowel++;
                c = a[i][j];
            }
        }
        w[vowel].push_back({c, i});
    }
    for(int i = 1; i <= 1000000; i++){
        if(!w[i].empty()){
            sort(w[i].begin(), w[i].end());
            for(int j = 0; j < w[i].size(); j++){
                if(j != w[i].size() - 1){
                    if(w[i][j].first == w[i][j + 1].first){
                        b.push({w[i][j].second, w[i][j + 1].second});
                        j++;
                    }
                    else c.push_back({i, w[i][j].second});
                }
                else c.push_back({i, w[i][j].second});
            }
        }
    }
    for(int i = 1; i < c.size(); i++){
        if(c[i - 1].first == c[i].first){
            d.push({c[i - 1].second, c[i].second});
            i++;
        }
    }
    vector<tuple<int, int, int, int>> ans;
    while(!b.empty() && !d.empty()){
        auto x = d.front();
        auto y = b.front();
        d.pop();
        b.pop();
        ans.push_back({x.first, y.first, x.second, y.second});
    }
    while(!b.empty()){
        auto x = b.front();
        b.pop();
        if(b.empty()) break;
        auto y = b.front();
        b.pop();
        ans.push_back({x.first, y.first, x.second, y.second});
    }
    cout << ans.size() << '\n';
    for(auto it : ans){
        cout << a[get<0>(it)] << ' ' << a[get<1>(it)] << '\n' << a[get<2>(it)] << ' ' << a[get<3>(it)] << '\n';
    }
    return 0;
}