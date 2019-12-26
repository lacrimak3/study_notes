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
    int l = 0, r = n - 1;
    int x = 0, y = n - 1;
    while(l < r){
        if(abs(a[l] + a[r]) < abs(a[x] + a[y])){
            x = l; y = r;
        }
        if(a[l] + a[r] > 0) r--;
        else l++;
    }
    cout << a[x] << ' ' << a[y];
    return 0;
}