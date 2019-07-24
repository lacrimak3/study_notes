#include <iostream>
using namespace std;

const int MOD = 10007;
const int h1 = 23;

struct _vector{
    int a[10];
    int len;
    _vector(): len(0) {}
    void push_back(int n){
        a[len++] = n;
    }
    int size(){
        return len;
    }
    int back(){
        return a[len - 1];
    }
    int operator[](int idx) const{
        return a[idx];
    }
    void clear(){
        len = 0;
    }
};

_vector table[MOD];
int n, m;
char a[501][501], b[501][501];
int pa[501][501], pb[501][501];

inline int mod(long long n){
    if(n >= 0) return n % MOD;
    else return ((-n / MOD + 1) * MOD + n) % MOD;
}

bool check(int len){
    for(int j = 0; j < m - len + 1; j++){
        for(int i = 0; i < MOD; i++)
            table[i].clear();
        for(int i = 0; i < n; i++){
            int key = 0;
            if(j == 0) key = pa[i][j + len - 1];
            else key = mod(pa[i][j + len - 1] - pa[i][j - 1]);
            if(table[key].size()){
                bool ok = true;
                for(int k = 0, x; k < table[key].size(); k++){
                    int idx = table[key][k];
                    for(x = 0; x < len; x++){
                        if(a[idx][j + x] != a[i][j + x]) break;
                    }
                    if(x == len){
                        ok = false;
                        break;
                    }
                }
                if(ok) table[key].push_back(i);
            }
            else table[key].push_back(i);
        }
        bool ok = true;
        for(int i = 0; i < n; i++){
            int key = 0;
            if(j == 0) key = pb[i][j + len - 1];
            else key = mod(pb[i][j + len - 1] - pb[i][j - 1]);
            if(table[key].size()){
                for(int k = 0, x; k < table[key].size(); k++){
                    int idx = table[key][k];
                    for(x = 0; x < len; x++){
                        if(a[idx][j + x] != b[i][j + x]) break; 
                    }
                    if(x == len){
                        ok = false;
                        break;
                    }
                }
                if(ok == false) break;
            }
        }
        if(ok) return true;
    }
    return false;
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pa[i][0] = a[i][0];
        int p = 1;
        for(int j = 1; j < m; j++){
            pa[i][j] = mod(pa[i][j - 1] + a[i][j] * p);
            p = mod(p * h1);
        }
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        pb[i][0] = b[i][0];
        int p = 1;
        for(int j = 1; j < m; j++){
            pb[i][j] = mod(pb[i][j - 1] + b[i][j] * p);
            p = mod(p * h1);
        }
    }
    int l = 1, r = m;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << r;
    return 0;
}