#include <bits/stdc++.h>
using namespace std;

int n;
bool a[4000][8000];
void solve(int n, int x, int y){
    if(n == 3){
        a[x][y + 2] = true;
        a[x + 1][y + 1] = a[x + 1][y + 3] = true;
        for(int i = 0; i < 5; i++) a[x + 2][y + i] = true;
        return;
    }
    solve(n / 2, x, y + n / 2);
    solve(n / 2, x + n / 2, y);
    solve(n / 2, x + n / 2, y + n);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve(n, 0, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n * 2; j++){
            if(!a[i][j]) cout << ' ';
            else cout << '*';
        }
        cout << '\n';
    }
    return 0;
}