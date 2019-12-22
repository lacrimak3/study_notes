#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1001;
int ans;
bool check[SIZE];
int n, a[101];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    check[1] = 1;
    for(long long i = 2; i <= SIZE; i++){
        if(check[i]) continue;
        for(long long j = i * i; j <= SIZE; j += i){
            check[j] = 1;
        }
    }
    cin >> n;
    for(int i = 0, t; i < n; i++){
        cin >> t;
        if(!check[t]) ans++;
    }
    cout << ans;
    return 0;
}