#include <bits/stdc++.h>
using namespace std;

int n;
int d[100001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    d[1] = 1;
    for(int i = 2; i <= n; i++){
        d[i] = i;
        for(int j = 2; j * j <= i; j++){
            d[i] = min(d[i], d[i - j * j] + 1);
        }
    }
    cout << d[n];
    return 0;
}