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
    int tc;
    cin >> tc;
    string t;
    getline(cin, t);
    while(tc--){
        string s;
        getline(cin, s);
        stack<char> a, b;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '<'){
                if(!a.empty()){
                    b.push(a.top());
                    a.pop();
                }
            }
            else if(s[i] == '>'){
                if(!b.empty()){
                    a.push(b.top());
                    b.pop();
                }
            }
            else if(s[i] == '-'){
                if(!a.empty()) a.pop();
            }
            else a.push(s[i]);
        }
        string ans;
        while(!a.empty()){
            ans += a.top();
            a.pop();
        }
        reverse(ans.begin(), ans.end());
        while(!b.empty()){
            ans += b.top();
            b.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}