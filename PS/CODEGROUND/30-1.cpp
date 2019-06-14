#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
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
        return (x2 - x1) * (y2 - y1) < (other.x2 - other.x1) * (other.y2 - other.y1);
    }
};
const int N = 5001;
int T;
int n, m, k;
Rec a[N];
int p[N];
bool include(Rec u, Rec v);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    int tc = 0;
    while(tc++ < T){
        cin >> n >> m >> k;
        for(int i = 0; i < k; i++){
            p[i] = 1;
            cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
        }
        sort(a, a + k);
        for(int i = 1; i < k; i++){
            for(int j = 0; j < i; j++){
                if(include(a[i], a[j])){
                    p[i] = max(p[i], p[j] + 1);
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