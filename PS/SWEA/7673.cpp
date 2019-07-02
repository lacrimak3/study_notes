#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
struct tf{
    int t, f;
    tf(){}
    tf(int t, int f) : t(t), f(f){}
};
const int INF = 1e9;
const int N = 1001;
int dx[] = {1, 0};
int dy[] = {0, 1};
int T;
int ans;
int n;
tf num[1000001];
tf d[N][N][2];
int a[N][N];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2; i <= 1000000; i++){
        int two = 0, five = 0;
        int t = i;
        while(t % 2 == 0){
            two++;
            t /= 2;
        }
        while(t % 5 == 0){
            five++;
            t /= 5;
        }
        num[i] = {two, five};
    }
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        cin >> n;
        for(int i = 0, t; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
                d[i][j][0] = d[i][j][1] = {INF, INF};
            }
        }
        d[0][0][0] = d[0][0][1] = num[a[0][0]];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == 0) continue;
                for(int k = 0; k < 2; k++){
                    int nx = i + dx[k], ny = j + dy[k];
                    if(nx >= n || ny >= n) continue;
                    if(d[nx][ny][0].t >= d[i][j][0].t + num[a[nx][ny]].t){
                        if(d[nx][ny][0].t == d[i][j][0].t + num[a[nx][ny]].f){
                            d[nx][ny][0].f = min(d[nx][ny][0].f, d[i][j][0].f + num[a[nx][ny]].f);
                        }
                        else{
                            d[nx][ny][0].t = d[i][j][0].t + num[a[nx][ny]].t;
                            d[nx][ny][0].f = d[i][j][0].f + num[a[nx][ny]].f;
                        }
                    }
                    if(d[nx][ny][1].f >= d[i][j][1].f + num[a[nx][ny]].f){
                        if(d[nx][ny][1].f == d[i][j][1].f + num[a[nx][ny]].f){
                            d[nx][ny][1].t = min(d[nx][ny][1].t, d[i][j][1].t + num[a[nx][ny]].t);
                        }
                        else{
                            d[nx][ny][1].f = d[i][j][1].f + num[a[nx][ny]].f;
                            d[nx][ny][1].t = d[i][j][1].t + num[a[nx][ny]].t;
                        }
                    }
                }
            }
        }
        ans = min({d[n - 1][n - 1][0].t, d[n - 1][n - 1][0].f, d[n - 1][n - 1][1].t, d[n - 1][n - 1][1].f});
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}