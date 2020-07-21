#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[1001];
priority_queue<long long> pq;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0, t; i < n; i++) {
        cin >> t;
        pq.push(-t);
    }
    while(m--) {
        long long x = pq.top();
        pq.pop();
        long long y = pq.top();
        pq.pop();
        pq.push(x + y);
        pq.push(x + y);
    }
    long long ans = 0;
    while(pq.size()) {
        ans += pq.top();
        pq.pop();
    }
    cout << -ans;
    return 0;
}