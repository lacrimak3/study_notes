#include <iostream>
using namespace std;
const int HASH_SIZE = 10000007;
const int PN = 23;
int hp, wp, hm, wm, ans;
char a[2001][2001], b[2001][2001];
int pa[2001], pb[2001][2001], a_hash;

inline int mod(long long n){
    if(n >= 0) return n % HASH_SIZE;
    return ((-n/HASH_SIZE + 1) * HASH_SIZE + n) % HASH_SIZE;
}

bool check(int x, int y){
    for(int i = 0; i < wp; i++){
        if(pa[i] != pb[x][i + y]) return false;
    }
    return true;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> hp >> wp >> hm >> wm;
    for(int i = 0; i < hp; i++) cin >> a[i];
    for(int i = 0; i < hm; i++) cin >> b[i];
    for(int i = 0; i < wp; i++){
        int t = 0, p = 1;
        for(int j = hp - 1; j >= 0; j--){
            t = mod(t + 1LL * a[j][i] * p);
            p = mod(p * PN);
        }
        pa[i] = t;
        a_hash = mod(t + 1LL * a_hash * PN);
    }
    for(int i = 0; i < wm; i++){
        int p = 1;
        for(int j = hp - 1; j >= 0; j--){
            pb[0][i] = mod(pb[0][i] + 1LL * b[j][i] * p);
            if(j != 0) p = mod(p * PN);
        }
        for(int j = 1; j <= hm - hp; j++){
            pb[j][i] = mod(PN * (pb[j - 1][i] - 1LL * b[j - 1][i] * p) + b[j + hp - 1][i]);
        }
    }
    for(int i = 0; i <= hm - hp; i++){
        int j = 0;
        int t = 0, p = 1;
        for(j = wp - 1; j >= 0; j--){
            t = mod(t + 1LL * pb[i][j] * p);
            if(j != 0) p = mod(p * PN);
        }
        if(t == a_hash && check(i, 0)) ans++;
        for(j = wp; j < wm; j++){
            t = mod(PN * (t - 1LL * pb[i][j - wp] * p) + pb[i][j]);
            if(t == a_hash && check(i, j - wp + 1)) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}