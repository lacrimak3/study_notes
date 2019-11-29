#include <bits/stdc++.h>
using namespace std;

int n;
int ans;
pair<int, int> a[100001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        int s, e;
        cin >> s >> e;
        a[i] = {e, s};
    }
    sort(a, a + n);
    int e = 0;
    for(int i = 0; i < n; i++){
        const auto &[ne, ns] = a[i];
        if(ns >= e){
            ans++;
            e = ne;
        }
    }
    cout << ans;
    return 0;
}