#include <bits/stdc++.h>
using namespace std;

int n;
char a[7000][7000];
void solve(int n, int x, int y){
    if(n == 3){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i == 1 && j == 1) continue;
                a[x + i][y + j] = '*';
            }
        }
        return;
    }
    int nxtN = n / 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 1 && j == 1) continue;
            solve(nxtN, x + i * nxtN, y + j * nxtN);
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve(n, 0, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!a[i][j]) cout << ' ';
            else cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}