#include <bits/stdc++.h>
using namespace std;

struct Node {
    int cnt = 0;
    vector<int> a;
    void push_back(int x) {
        a.push_back(x);
    }
    int size() {
        return a.size();
    }
};

int n, m;
Node g[200001];
int ans[200001];
bool v[200001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(ans, -1, sizeof(ans));
    cin >> n;
    for(int i = 0, t; i < n; i++) {
        cin >> t;
        while(t) {
            g[i + 1].push_back(t);
            g[t].push_back(i + 1);
            cin >> t;
        }
    }
    queue<int> q;
    cin >> m;
    for(int i = 0, t; i < m; i++) {
        cin >> t;
        q.push(t);
        v[t] = 1;
        ans[t] = 0;
    }
    while(q.size()) {
        int len = q.size();
        while(len--) {
            int now = q.front();
            q.pop();
            for(int nxt : g[now].a) {
                if(v[nxt]) continue;
                g[nxt].cnt++;
                if(g[nxt].cnt >= g[nxt].size() / 2) {
                    v[nxt] = 1;
                    ans[nxt] = ans[now] + 1;
                    q.push(nxt);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return 0;
}