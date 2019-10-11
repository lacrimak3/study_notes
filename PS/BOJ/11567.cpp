#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m, r1, c1, r2, c2;
bool a[501][501];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs(int x, int y);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j= 0; j < m; j++){
            if(s[j] == 'X') a[i][j] = true;
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    a[r1][c1] = false;
    dfs(r1, c1);
    cout << "NO";
    return 0;
}

void dfs(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m) return;
    if(x == r2 && y == c2 && a[x][y]){
        cout << "YES";
        exit(0);
    }
    if(a[x][y]) return;
    a[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        dfs(nx, ny);
    }
}