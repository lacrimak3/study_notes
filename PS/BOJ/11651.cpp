#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[100001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
    sort(a, a + n);
    for(int i = 0; i < n; i++)
        cout << a[i].second << ' ' << a[i].first << '\n';
    return 0;
}