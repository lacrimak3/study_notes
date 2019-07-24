#include <iostream>
using namespace std;

const int MOD = 100000;
const int h1 = 23;

struct _vector{
    int a[10], len;
    _vector(){
        len = 0;
    }
    int size(){
        return len;
    }
    void clear(){
        len = 0;
    }
    void push_back(int v){
        a[len++] = v;
    }
    void pop_back(){
        len--;
    }
    int operator[](int i) const{
        return a[i];
    }
    int &operator[](int i){
        return a[i];
    }
    int empty(){
        return len == 0;
    }
};

int L;
_vector table[MOD];
char s[200001];
inline int mod(long long n){
    if(n >= 0) return n % MOD;
    else return ((-n / MOD + 1) * MOD + n) % MOD;
}

bool check(int len){
    int key = 0;
    for(int i = 0; i < MOD; i++) table[i].clear();
    int p1 = 1, p2 = 1;
    for(int i = 0; i < len - 1; i++){
        key = mod(1LL * key * h1 + s[i]);
        p1 = mod(p1 * h1);
    }
    for(int i = len - 1; s[i] != 0; i++){
        key = mod(1LL * key * h1 + s[i]);
        if(!table[key].empty()){
            int idx = i - len + 1;
            for(int i = 0; i < table[key].size(); i++){
                bool ok = true;
                for(int j = 0; j < len; j++){
                    if(s[j + table[key][i]] != s[j + idx]){
                        ok = false;
                        break;
                    }
                }
                if(ok) return true;
            }
        }
        table[key].push_back(i - len + 1);
        key = mod(key - 1LL * s[i - len + 1] * p1);
    }
    return false;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> L >> s;
    int l = 0, r = L;
    while(l < r){
        int m = l + r + 1 >> 1;
        if(check(m)) l = m;
        else r = m - 1;
    }
    cout << r << '\n';
    return 0;
}