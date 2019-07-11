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
int n, sz;
int d[N];
pair<int, int> a[1000000];

bool cmp(const pair<int, int> &x, const pair<int, int> &y);
void update(int id, int val);
int findMax(int l, int r, int node_num, int nl, int nr);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n, cmp);
    sz = 1;
    while(sz < n) sz <<= 1;
    for(int i = 0; i < n; i++){
        int val = findMax(0, a[i].second, 1, 0, sz - 1);
        update(a[i].second, val + 1);
    }
    cout << d[1] << '\n';
    return 0;
}

bool cmp(const pair<int, int> &x, const pair<int, int> &y){
    if(x.first == y.first) return x.second > y.second;
    else return x.first < y.first;
}

void update(int id, int val){
    id += sz;
    d[id] = val;
    while(id > 1){
        id /= 2;
        d[id] = max(d[id * 2], d[id * 2 + 1]);
    }
}

int findMax(int l, int r, int node_num, int nl, int nr){
    if(r < nl || l > nr) return 0;
    if(l <= nl && nr <= r) return d[node_num];
    int mid = nl + nr >> 1;
    return max(findMax(l, r, node_num * 2, nl, mid), findMax(l, r, node_num * 2 + 1, mid + 1, nr));
}