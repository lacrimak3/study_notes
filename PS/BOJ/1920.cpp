#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int m;
    cin >> m;
    for(int i = 0, t; i < m; i++){
        cin >> t;
        cout << binary_search(a, a + n, t) << '\n';
    }
    return 0;
}