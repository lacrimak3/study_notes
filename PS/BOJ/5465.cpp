#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
//#include <map>
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

int n, s;
char map[800][801];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dist_bee[800][801], dist_bear[800][801];
pair<int, int> M, D;
bool solve(int time);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    queue<pair<int, int>> bee;
    for(int i = 0; i < n; i++){
        cin >> map[i];
        for(int j = 0; j < n; j++){
            dist_bee[i][j] = -1;
            if(map[i][j] == 'H'){
                dist_bee[i][j] = 0;
                bee.push({i, j});
            }
            if(map[i][j] == 'M') M = {i, j};
            if(map[i][j] == 'D') D = {i, j};
        }
    }
    while(bee.size()){
        int len = bee.size();
        while(len--){
            int x, y;
            tie(x, y) = bee.front();
            bee.pop();
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(dist_bee[nx][ny] != -1 || map[nx][ny] == 'T' || map[nx][ny] == 'D') continue;
                dist_bee[nx][ny] = dist_bee[x][y] + 1;
                bee.push({nx, ny});
            }
        }
    }
    dist_bee[D.first][D.second] = INF;
    int l = 0, r = n * n + 1;
    if(!solve(0)){
        cout << -1 << '\n';
        return 0;
    }
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(solve(mid)){
            l = mid;
        }
        else r = mid - 1;
    }
    cout << r << '\n';
    return 0;
}

bool solve(int time){
    if(time >= dist_bee[M.first][M.second]) return false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist_bear[i][j] = -1;
        }
    }
    dist_bear[M.first][M.second] = time;
    queue<pair<int, int>> q;
    q.push(M);
    while(q.size()){
        int dist = 0;
        int t = dist_bear[q.front().first][q.front().second];
        while(dist < s){
            dist++;
            int len = q.size();
            while(len--){
                int x, y;
                tie(x, y) = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(dist_bear[nx][ny] != -1 || map[nx][ny] == 'T' || t >= dist_bee[nx][ny]) continue;
                    if(dist == s && t + 1 >= dist_bee[nx][ny]) continue;
                    if(map[nx][ny] == 'D') return true;
                    dist_bear[nx][ny] = t + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    return false;
}