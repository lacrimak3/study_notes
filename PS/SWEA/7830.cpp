#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int T;
int ans;
int n, m;
int a[751][751];
vector<pair<int, int>> p;
int checkDia(int x, int y, int &L);
void findMax(int x, int y);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        p.clear();
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            string s;
            cin >> s;
            for(int j = 0; j < m; j++){
                a[i][j] = s[j] - '0';
                if(a[i][j]){
                    ans = 1;
                    p.push_back({i, j});
                }
            }
        }
        if(ans){
            for(auto it : p){
                int x = it.first, y = it.second;
                findMax(x, y);
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}

void findMax(int x, int y){
    int l = min((n - x - 1) / 2, min(m - y - 1, y)), t;
    if(l < ans) return;
    while((t = checkDia(x, y, l)) != -1){
            if(t) ans = l + 1;
            l--;
            if(l < ans) break;
    }
}

int checkDia(int x, int y, int &L){
    if(y - L < 0 || x + 2 * L >= n || y + L >= m) return -1;
    int direction = 0;
    for(int i = 1; i <= L; i++){
        if(a[x + i][y - i] == 0 || a[x + i][y + i] == 0){
            L = i - 1;
            return 0;
        }
        if(a[x + L + i][y - L + i] == 0 || a[x + L + i][y + L - i] == 0) return 0;
    }
    return 1;
}