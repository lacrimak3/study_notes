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
int n, q, sz = 1;
long long seg[N];
void init();
void update(int idx, int val);
long long sum(int l, int r, int node_num, int nl, int nr);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    while(sz < n) sz <<= 1;
    while(q--){
        int x, y, z;
        cin >> x >> y >> z;
        if(x == 0){
            if(y > z) swap(y, z);
            cout << sum(y - 1, z - 1, 1, 0, sz - 1) << '\n';
        }
        else update(y - 1, z);
    }
    return 0;
}

void init(){
    for(int i = sz - 1; i > 0; i--)
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
}

void update(int idx, int val){
    idx += sz;
    seg[idx] = val;
    while(idx > 1){
        idx >>= 1;
        seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
    }
}

long long sum(int l, int r, int node_num, int nl, int nr){
    if(l > nr || r < nl) return 0;
    if(l <= nl && nr <= r) return seg[node_num];
    int mid = nl + nr >> 1;
    return sum(l, r, node_num * 2, nl, mid) + sum(l, r, node_num * 2 + 1, mid + 1, nr);
}