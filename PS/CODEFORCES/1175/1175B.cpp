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

stack<pair<int, int>> st1, st2;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    cin.ignore();
    long long ans = 0;
    bool ok = true;
    long long t = 1;
    int cnt = 0;
    while(T--){
        string s;
        cin >> s;
        if(s == "add"){
            while(!st1.empty()){
                t *= st1.top().first;
                if(t >= (1LL << 32)) break;
                st1.pop();
            }
            ans += t;
            if(ans >= (1LL << 32)){
                ok = false;
                break;
            }
        }
        else if(s == "for"){
            int n;
            cin >> n;
            st1.push({n, cnt});
            st2.push({n, cnt++});
        }
        else if(!st2.empty()){
            if(!st1.empty() && st2.top().second == st1.top().second)
                st1.pop();
            else t /= st2.top().first;
            st2.pop();
        }
    }
    if(ok) cout << ans;
    else cout << "OVERFLOW!!!";
    return 0;
}