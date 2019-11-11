#include <bits/stdc++.h>
using namespace std;

int n;
int a[2001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0, x; i < n; i++){
        cin >> x;
        a[x + 1000]++;
    }
    for(int i = 0; i <= 2000; i++)
        if(a[i]) cout << i - 1000 << ' ';
    return 0;
}