#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int d[100];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    int maxv = -1;
    int maxidx = -1;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k <= c; k++) {
                d[i + j + k]++;
            }
        }
    }
    for(int i = 0; i < 100; i++) {
        if(d[i] > maxv) {
            maxv = d[i];
            maxidx = i;
        }
    }
    cout << maxidx;
    return 0;
}