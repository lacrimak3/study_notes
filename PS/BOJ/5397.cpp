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
        list<char> a;
        auto it = a.begin();
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '<'){
                if(it != a.begin()) it--;
            }
            else if(s[i] == '>'){
                if(it != a.end()) it++;
            }
            else if(s[i] == '-'){
                if(it != a.begin()){
                    it--;
                    it = a.erase(it);
                }
            }
            else a.insert(it, s[i]);
        }
        for(auto c : a)
            cout << c;
        cout << '\n';
    }
    return 0;
}