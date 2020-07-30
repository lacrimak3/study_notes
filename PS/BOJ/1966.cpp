#include <bits/stdc++.h>
using namespace std;

struct node {
    int x;
    bool c;
};

int tc;
int n, m;
queue<node> q;
int num[10];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while (tc--) {
        memset(num, 0, sizeof(num));
        while (q.size()) q.pop();
        cin >> n >> m;
        for (int i = 0, x; i < n; i++) {
            cin >> x;
            bool c = false;
            if (m == i) c = true;
            q.push({x, c});
            num[x]++;
        }
        int ans = 0;
        while (q.size()) {
            int x = q.front().x;
            bool c = q.front().c;
            q.pop();
            bool ok = false;
            int i;
            for (i = x + 1; i < 10; i++) {
                if (num[i]) break;
            }
            if (i == 10) {
                num[x]--;
                ans++;
                if (c) break;
                continue;
            }
            q.push({x, c});
        }
        cout << ans << '\n';
    }
    return 0;
}