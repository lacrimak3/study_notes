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

const int N = 2100000;
int n, m, k, sz = 1;
long long a[N];
void init();
void update(int idx, int val);
long long mul(int l, int r, int node_num, int nl, int nr);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while(sz < n) sz <<= 1;
    for(int i = 0; i < n; i++) cin >> a[i + sz];
    for(int i = n; i < sz; i++) a[i + sz] = 1;
    init();
    m += k;
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;
        if(x == 1){
            update(y - 1, z);
        }
        else cout << mul(y - 1, z - 1, 1, 0, sz - 1) << '\n';
    }
    return 0;
}

void init(){
    for(int i = sz - 1; i > 0; i--)
        a[i] = (a[i * 2] * a[i * 2 + 1]) % MOD;
}

void update(int idx, int val){
    idx += sz;
    a[idx] = val;
    while(idx > 1){
        idx /= 2;
        a[idx] = (a[idx * 2] * a[idx * 2 + 1]) % MOD;
    }
}

long long mul(int l, int r, int node_num, int nl, int nr){
    if(l > nr || r < nl) return 1;
    if(l <= nl && nr <= r) return a[node_num];
    int mid = nl + nr >> 1;
    return (mul(l, r, node_num * 2, nl, mid) * mul(l, r, node_num * 2 + 1, mid + 1, nr)) % MOD;
}