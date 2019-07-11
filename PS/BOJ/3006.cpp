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

const int N = 300001;
int n, sz = 1;
pair<int, int> a[100001];
int seg[N];
void init();
void update(int idx, int val);
int query(int l, int r, int node_num, int nl, int nr);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    while(sz < n) sz <<= 1;
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
        seg[i + sz] = 1;
    }
    sort(a, a + n);
    init();
    for(int i = 0; i < n / 2; i++){
        cout << query(0, a[i].second, 1, 0, sz - 1) - 1 << '\n';
        update(a[i].second, 0);
        cout << query(a[n - 1 - i].second, n - 1, 1, 0, sz - 1) - 1 << '\n';
        update(a[n - 1 - i].second, 0);
    }
    if(n % 2) cout << "0\n";
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

int query(int l, int r, int node_num, int nl, int nr){
    if(l > nr || r < nl) return 0;
    if(l <= nl && nr <= r) return seg[node_num];
    int m = nl + nr >> 1;
    return query(l, r, node_num * 2, nl, m) + query(l, r, node_num * 2 + 1, m + 1, nr);
}