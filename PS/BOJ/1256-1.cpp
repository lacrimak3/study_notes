#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9;
int n, m, k;
int comb[201][201];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i < 201; i++){
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; j++){
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
            if(comb[i][j] > MAX) comb[i][j] = MAX + 1;
        }
    }
    cin >> n >> m >> k;
    if(comb[n + m][m] < k){
        cout << -1;
        return 0;
    }
    while(n || m){
        if(!n){
            cout << 'z';
            m--;
            continue;
        }
        if(!m){
            cout << 'a';
            n--;
            continue;
        }
        if(comb[n + m - 1][m] < k){
            k -= comb[n + m - 1][m];
            cout << 'z';
            m--;
        }
        else{
            cout << 'a';
            n--;
        }
    }
    return 0;
}