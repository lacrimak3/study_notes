#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int dp = 0, cc = -1;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;
char piet[100][101];
int comp[100][101];
pair<int, int> D[10001][4][3];
void findComp(int x, int y, int cnt);
void solve(int x, int y);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> piet[i];
    for(int i = 0, cnt = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!comp[i][j]){
                for(int x = 0; x < 4; x++){
                    for(int y = 0; y < 3; y++)
                        D[cnt][x][y] = {i, j};
                }
                findComp(i, j, cnt++);
            }
        }
    }
    solve(0, 0);
    return 0;
}

void findComp(int x, int y, int cnt){
    if(y >= D[cnt][0][0].second){
        if(y > D[cnt][0][0].second) D[cnt][0][0] = {x, y};
        else D[cnt][0][0].first = min(D[cnt][0][0].first, x);
    }
    if(y >= D[cnt][0][2].second){
        if(y > D[cnt][0][2].second) D[cnt][0][2] = {x, y};
        else D[cnt][0][2].first = max(D[cnt][0][2].first, x);
    }
    if(x >= D[cnt][1][0].first){
        if(x > D[cnt][1][0].first) D[cnt][1][0] = {x, y};
        else D[cnt][1][0].second = max(D[cnt][1][0].second, y);
    }
    if(x >= D[cnt][1][2].first){
        if(x > D[cnt][1][2].first) D[cnt][1][2] = {x, y};
        else D[cnt][1][2].second = min(D[cnt][1][2].second, y);
    }
    if(y <= D[cnt][2][0].second){
        if(y < D[cnt][2][0].second) D[cnt][2][0] = {x, y};
        else D[cnt][2][0].first = max(D[cnt][2][0].first, x);
    }
    if(y <= D[cnt][2][2].second){
        if(y < D[cnt][2][2].second) D[cnt][2][2] = {x, y};
        else D[cnt][2][2].first = min(D[cnt][2][2].first, x);
    }
    if(x <= D[cnt][3][0].first){
        if(x < D[cnt][3][0].first) D[cnt][3][0] = {x, y};
        else D[cnt][3][0].second = min(D[cnt][3][0].second, y);
    }
    if(x <= D[cnt][3][2].first){
        if(x < D[cnt][3][2].first) D[cnt][3][2] = {x, y};
        else D[cnt][3][2].second = max(D[cnt][3][2].second, y);
    }
    
    comp[x][y] = cnt;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(comp[nx][ny] || piet[x][y] != piet[nx][ny]) continue;
        findComp(nx, ny, cnt);
    }
}

void solve(int x, int y){
    cout << piet[x][y];
    for(int i = 0; i < 8; i++){
        int nx = x, ny = y;
        nx = D[comp[x][y]][dp][cc + 1].first;
        ny = D[comp[x][y]][dp][cc + 1].second;
        nx += dx[dp];
        ny += dy[dp];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && piet[nx][ny] != 'X'){
            solve(nx, ny);
            break;
        }
        if(i % 2 == 0) cc = -cc;
        else dp = (dp + 1) % 4;
    }
}