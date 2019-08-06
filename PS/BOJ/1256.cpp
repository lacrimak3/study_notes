#include <algorithm>
#include <iostream>
using namespace std;
int comb[201][201];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < 201; i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; j++){
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            if(comb[i][j] > 1e9) comb[i][j] = 1e9 + 1;
        }
    }
    int n, m, k;
    cin >> n >> m >> k;
    if(comb[n + m][m] < k){
        cout << -1;
        return 0;
    }
    string ans = "";
    while(n || m){
        if(!n){
            ans += 'z';
            m--;
            continue;
        }
        if(!m){
            ans += 'a';
            n--;
            continue;
        }
        if(comb[n + m - 1][n - 1] < k){
            ans += 'z';
            k -= comb[n + m - 1][n - 1];
            m--;
        }
        else{
            ans += 'a';
            n--;
        }
    }
    cout << ans;
    return 0;
}