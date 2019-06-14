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

struct Rec{
    long long x1, y1, x2, y2;
    Rec() {}
    Rec(long long x1, long long y1, long long x2, long long y2) : x1(x1), y1(y1), x2(x2), y2(y2){}
    bool operator < (const Rec &other) const {
        return (x2 - x1) * (y2 - y1) > (other.x2 - other.x1) * (other.y2 - other.y1);
    }
};
const int N = 5001;
int T;
int n, m, k;
Rec a[N];
int ind[N], p[N];
bool include(Rec u, Rec v);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    int tc = 0;
    while(tc++ < T){
        memset(p, 0, sizeof(p));
        memset(ind, 0, sizeof(ind));
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++){
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            a[i] = {x1, y1, x2, y2};
        }
        sort(a, a + k);
        vector<vector<int>> g(k);
        for(int i = 0; i < k; i++){
            for(int j = i + 1; j < k; j++){
                if(include(a[i], a[j])){
                    g[j].push_back(i);
                    ind[i]++;
                }
            }
        }
        queue<int> Q;
        for(int i = 0; i < k; i++){
            if(ind[i] == 0){
                Q.push(i);
                p[i] = 1;
            }
        }
        while(!Q.empty()){
            int now = Q.front();
            Q.pop();
            for(int nxt : g[now]){
                if(--ind[nxt] == 0){
                    Q.push(nxt);
                    p[nxt] += p[now] + 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < k; i++){
            ans = max(ans, p[i]);
        }
        cout << "Case #" << tc << '\n';
        cout << ans << '\n';
    }
    return 0;
}

bool include(Rec u, Rec v){
    return (v.x1 >= u.x1 && v.y1 >= u.y1 && v.x2 <= u.x2 && v.y2 <= u.y2);
}