#include <bits/stdc++.h>
using namespace std;
constexpr int MAX = 987654321;
int d[200001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 200000; i--;) d[i] = MAX;

    priority_queue<pair<int, int>> q;
    for (int i = n; i <= 200000; i *= 2) {
        d[i] = 0;
        q.push({0, i});
        if(i == 0) break;
    }

    while (q.size()) {
        int cur = q.top().second, w = -q.top().first;
        q.pop();
        int nxt = cur + 1;
        int i;
        for (i = nxt; i <= 200000; i *= 2) {
            if (d[i] > w + 1) {
                d[i] = w + 1;
                q.push({-d[i], i});
            }
            if (i == 0) break;
        }
        nxt = cur - 1;
        if (nxt < 0) continue;
        for (i = nxt; i <= 200000; i *= 2) {
            if (d[i] > w + 1) {
                d[i] = w + 1;
                q.push({-d[i], i});
            }
            if (i == 0) break;
        }
    }
    cout << d[m];

    return 0;
}