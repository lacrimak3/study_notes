#include <iostream>
#include <unordered_set>
using namespace std;

const int MOD = 1e9 + 7;
const int h1 = 23, h2 = 17;

int n;
char a[10][100002];
inline long long makeHash(long long x, long long y){
    return x * 1e9 + y;
}

inline long long mod(long long n){
    if(n >= 0) return n % MOD;
    else return ((-n / MOD + 1) * MOD + n) % MOD;
}

bool check(int len){
    unordered_set<long long> us[10];
    for(int i = 0; i < n; i++){
        long long v1 = 0, v2 = 0, p1 = 1, p2 = 1;
        for(int j = 0; j < len - 1; j++){
            v1 = mod(v1 * h1 + a[i][j]);
            p1 = mod(p1 * h1);
            v2 = mod(v2 * h2 + a[i][j]);
            p2 = mod(p2 * h2);
        }
        for(int j = len - 1; a[i][j] != 0; j++){
            v1 = mod(v1 * h1 + a[i][j]);            
            v2 = mod(v2 * h2 + a[i][j]);
            long long key = makeHash(v1, v2);
            if(i == 0 || us[i - 1].count(key)) us[i].insert(key);
            v1 = mod(v1 - 1LL * a[i][j - len + 1] * p1);
            v2 = mod(v2 - 1LL * a[i][j - len + 1] * p2);
        }
    }
    if(us[n - 1].size()) return true;
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int l = 0, r = 987654321;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        int len = 0;
        for(int j = 0; a[i][j] != 0; j++) len++;
        if(r > len) r = len;
    }
    while(l < r){
        int m = l + r + 1 >> 1;
        if(check(m)) l = m;
        else r = m - 1;
    }
    cout << r;
    return 0;
}