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

int n, x;
bool c[1 << 18];
vector<int> b;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    c[0] = 1;
    for(int i = 1; i < (1 << n); i++){
        if(c[i ^ x]) continue;
        b.push_back(i);
        c[i] = true;
    }
    cout << b.size() << '\n';
    for(int i = 0; i < b.size(); i++){
        if(i == 0) cout << b[i] << ' ';
        else cout << (b[i] ^ b[i - 1]) << ' ';
    }
    return 0;
}