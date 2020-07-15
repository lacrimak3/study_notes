#include <bits/stdc++.h>
using namespace std;

int n;
int b[300001];
bool cmp(const int &x, const int &y) {
    return x > y;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(b, b + n, cmp);
    int max = 0;
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (b[i] + i + 1 >= max) {
            max = b[i] + i + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if(b[i] + n < max) ans--;
    }
    cout << ans;
    return 0;
}