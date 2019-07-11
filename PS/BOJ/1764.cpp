#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e4 + 7;
int n, m;
vector<int> table[MOD];
string s[500001];
int makeHash(string &s);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<string> ans;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        table[makeHash(s[i])].push_back(i);
    }
    for(int i = 0; i < m; i++){
        string t;
        cin >> t;
        int n = makeHash(t);
        if(!table[n].empty()){
            for(auto j : table[n]){
                if(t == s[j]){
                    ans.push_back(t);
                }
            }
        }
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(auto &i : ans){
        cout << i << '\n';
    }
    return 0;
}

int makeHash(string &s){
    long long ret = 5381;
    for(auto c : s){
        ret = ((ret << 5) + ret + c) % MOD;
    }
    return ret;
}