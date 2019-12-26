#include <bits/stdc++.h>
using namespace std;

const int SIZE = 500001;

int n, m;
int a[SIZE];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> m;
    for(int i = 0, t; i < m; i++){
        cin >> t;
        cout << upper_bound(a, a + n, t) - lower_bound(a, a + n, t) << ' ';
    }
    return 0;
}