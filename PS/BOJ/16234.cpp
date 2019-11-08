#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, l, r;
int a[51][51];
vector<pair<int, int>> uni;
int v[51][51], cnt = 1;
void dfs(int x, int y){
    uni.emplace_back(x, y);
    v[x][y] = cnt;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(v[nx][ny] >= cnt) continue;
        int diff = abs(a[x][y] - a[nx][ny]);
        if(diff >= l && diff <= r)
            dfs(nx, ny);
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    int ans = 0;
    while(1){
        bool ok = false;
        cnt++;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                uni.clear();
                if(v[i][j] < cnt) dfs(i, j);
                if(uni.size() > 1){
                    int val = 0;
                    for(auto &[x, y] : uni) val += a[x][y];
                    val /= uni.size();
                    for(auto &[x, y] : uni) a[x][y] = val;
                    ok = true;
                }
            }
        }
        if(!ok) break;
        ans++;
    }
    cout << ans;
    return 0;
}