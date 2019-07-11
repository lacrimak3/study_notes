#include <cstring>
#include <iostream>
using namespace std;

template <typename A, typename B>
class _pair{
public:
    A x; B y;
    _pair(A a, B b) : x(a), y(b){}
    _pair(){}
    bool operator < (const _pair &other) const{
        if(x == other.x) return y < other.y;
        else return x < other.y;
    }
};
const int N = 2501;
int T;
int ans;
int n, m;
char a[50][51];
int p[50][51];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dfront, dback, front, back;
_pair<int, int> demon[N];
_pair<int, int> q[N];
bool v[50][51];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        memset(v, 0, sizeof(v));
        ans = front = back = dfront = dback = 0;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        _pair<int, int> s, e;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == '*'){
                    demon[dback++] = {i, j};
                }
                if(a[i][j] == 'S') s = {i, j};
                if(a[i][j] == 'D') e = {i, j};
            }
        }
        p[s.x][s.y] = 0;
        q[back++] = s;
        bool ok = false;
        while(front != back){
            int len = dback - dfront;
            while(len--){
                int x = demon[dfront].x, y = demon[dfront].y;
                dfront++;
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(a[nx][ny] == 'X' || a[nx][ny] == 'D' || a[nx][ny] == '*') continue;
                    a[nx][ny] = '*';
                    demon[dback++] = {nx, ny};
                }
            }
            len = back - front;
            while(len--){
                int x = q[front].x, y = q[front].y;
                front++;
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(a[nx][ny] == 'X' || a[nx][ny] == '*' || v[nx][ny]) continue;
                    if(a[nx][ny] == 'D'){
                        ok = true;
                        ans = p[x][y] + 1;
                        break;
                    }
                    q[back++] = {nx, ny};
                    v[nx][ny] = true;
                    p[nx][ny] = p[x][y] + 1;
                }
                if(ok) break;
            }
            if(ok) break;
        }
        cout << '#' << tc << ' ';
        if(ans) cout << ans << '\n';
        else cout << "GAME OVER\n";
    }
    return 0;
}