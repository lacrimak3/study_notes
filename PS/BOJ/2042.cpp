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
int n, m, k, size;
long long a[N];
void init();
void update(int idx, long long val);
long long sum(int l, int r, int node, int nl, int nr);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    m += k;
    size = 1;
    while(size < n) size *= 2;
    for(int i = 0; i < n; i++)
        cin >> a[i + size];
    init();

    while(m--){
        long long x, y, z;
        cin >> x >> y >> z;
        if(x == 1) update(y - 1, z);
        else cout << sum(y - 1, z - 1, 1, 0, size - 1) << '\n';
    }
    
    return 0;
}

void init(){
    for(int i = size - 1; i > 0; i--)
        a[i] = a[i * 2] + a[i * 2 + 1];
}

void update(int idx, long long val){
    idx += size;
    a[idx] = val;
    while(idx > 1){
        idx /= 2;
        a[idx] = a[idx * 2] + a[idx * 2 + 1];
    }
}

long long sum(int l, int r, int node, int nl, int nr){
    if(nr < l || nl > r) return 0;
    if(l <= nl && nr <= r) return a[node];
    int mid = (nl + nr) / 2;
    return sum(l, r, node * 2, nl, mid) + sum(l, r, node * 2 + 1, mid + 1, nr);
}