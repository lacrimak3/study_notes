#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int T;
long long ans;
int n;
long long d[27][1001];
void calc();
long long solve(int x);
int main(void) {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin >> T;
    calc();
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        cin >> n;
        for(int i = 2; ; i++){
            long long t;
            if((t = solve(i)) == 0) break;
            ans += t;
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}

void calc(){
    for(int i = 0; i < 27; i++){
        for(int j = 2; j < 1001; j++){
            if(i == 0) d[i][j] = 1 + j + j * j + j * j * j;
            else d[i][j] = d[i - 1][j] * j + 1;
            if(d[i][j] >= 1e9){
                d[i][j] = 1e9 + 1;
                break;
            }
        }
    }
}

long long solve(int x){
    long long ret = 0;
    if(x <= 3){
        for(int s = 1; s <= n; s++){
            long long e;
            if(x == 2) e = n / s - 1;
            else{
                long long t = -3LL * s * s + 4LL * s * n;
                if(t < 0) break;
                e = (-s + sqrt(t)) / (2 * s);
            }
            if(e <= s) break;
            ret += 1LL * (s + e + 1) * (e - s) / 2;
        }
        return ret;
    }
    long long now = d[x - 4][2];
    for(int b = 2; now <= n; b++){
        ret += min((n / now), (b - 1LL)) * b;
        now = d[x - 4][b + 1];
    }
    return ret;
}