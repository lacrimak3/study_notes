#include <bits/stdc++.h>
using namespace std;

constexpr int MAX = 100001;
int n;
int a[MAX];
int sum[MAX], rsum[MAX];
long long ans;
long long d[MAX];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            sum[i] = a[i];
            rsum[n - i - 1] = a[n - i - 1];
        } else {
            sum[i] = sum[i - 1] + a[i];
            rsum[n - i - 1] = rsum[n - i] + a[n - i - 1];
        }
    }
    vector<int> hidx, qidx, rqidx;

    for (int i = 0; i < n; i++) {
        if (sum[i] == sum[n - 1] / 2 && (i != 0 && i != n - 1)) hidx.push_back(i);
        if (sum[i] == sum[n - 1] / 4 && (i < n - 3)) qidx.push_back(i);
        if (rsum[i] == rsum[0] / 4 && (i > 2)) rqidx.push_back(i);
    }
    int qi = 0, rqi = 0;
    for (int i = 0; i < hidx.size(); i++) {
        while (qi < qidx.size() && qidx[qi] < hidx[i]) qi++;
        while (rqi < rqidx.size() && rqidx[rqi] <= hidx[i] + 1) rqi++;
        d[hidx[i]] = (long long)(qi * (rqidx.size() - rqi));
    }
    for (int i = 0; i < n; i++) ans += d[i];
    cout << ans;
    return 0;
}