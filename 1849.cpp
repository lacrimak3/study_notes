#include <iostream>
#include <cstring>
using namespace std;

const int INF = 1e9;
int T;
int n, m;
int p[100001], wgt[100001], r[100001];
void Union(int u, int v, int w);
int Find(int u);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        cout << '#' << tc << ' ';
        memset(wgt, 0, sizeof(wgt));
        memset(r, 0, sizeof(r));
        cin >> n >> m;
        for(int i = 1; i <= n; ++i) p[i] = i;
        while(m--){
            char c;
            cin >> c;
            if(c == '!'){
                int a, b, w;
                cin >> a >> b >> w;
                Union(a, b, w);
            }
            else{
                int a, b;
                cin >> a >> b;
                int pa = Find(a);
                int pb = Find(b);
                if(pa != pb) cout << "UNKNOWN ";
                else cout << wgt[b] - wgt[a] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
void Union(int u, int v, int w){
    w += wgt[u] - wgt[v];
    u = Find(u);
    v = Find(v);
    if(u == v) return;
    if(r[u] < r[v]){
        p[u] = v;
        wgt[u] -= w;
    }
    else{
        p[v] = u;
        wgt[v] += w;
    }
    if(r[u] == r[v]) r[u]++;
}
int Find(int u){
    if(u == p[u]) return u;
    wgt[u] += wgt[p[u]];
    return p[u] = Find(p[u]);
}