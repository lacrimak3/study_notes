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

ll n, m, GCD;
int q;
inline ll gcd(ll x, ll y){
    return y ? gcd(y, x % y) : x;
}
ll findGcdSection(ll x, ll y){
    ll sn;
    if(x == 1) sn = n / GCD;
    else sn = m / GCD;
    return (y - 1) / sn;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    GCD = gcd(n, m);
    while(q--){
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        if(findGcdSection(sx, sy) == findGcdSection(ex, ey))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}