#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int T;
vector<int> ans;
int n, a[5001], len;
pair<int, int> b[5001];
bool solve(int now, int cnt){
    if(cnt == n) return true;
    if(now > len) return false;
    for(int nxt = 1; nxt <= len; nxt++){
        if(b[nxt].first != b[now].first + 1 && b[nxt].second){
            b[nxt].second--;
            ans.push_back(b[nxt].first);
            if(solve(nxt, cnt + 1)) return true;
            b[nxt].second++;
            ans.pop_back();
        }
    }
    return false;
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans.clear();
        len = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++){
            if(a[i - 1] != a[i]){
                b[++len].first = a[i];
                b[len].second = 1;
            }
            else b[len].second++;
        }
        b[0].first = -10;
        b[0].second = 1;
        solve(0, 0);
        cout << '#' << tc << ' ';
        for(int i : ans) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}