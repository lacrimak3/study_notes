#include <cstring>
#include <iostream>
using namespace std;

int T;
int ans;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        string s;
        int a[10] = {0};
        cin >> s;
        for(char c : s) a[c - '0']++;
        for(int i = 0; i < 10; i++) if(a[i]) ans++;
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}