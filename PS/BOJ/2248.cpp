#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int comb[32][32];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    comb[0][0] = 1;
    for(int i = 1; i < 32; i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; j++){
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
    ll N, L, I;
    cin >> N >> L >> I;
    string ans = "";
    while(N){
        if(!L){
            ans += '0';
            N--;
            continue;
        }
        ll t = 0;
        for(int i = 0; i < min(L + 1, N); i++){
            t += comb[N - 1][N - 1 - i];
        }
        if(t < I){
            ans += '1';
            I -= t;
            L--;
            N--;
        }
        else{
            ans += '0';
            N--;
        }
    }
    cout << ans;
    return 0;
}