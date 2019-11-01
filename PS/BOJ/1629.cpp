#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int dpow(int a, int b){
    int ret = 1;
    while(b){
        if(b & 1) ret = (1LL * ret * a) % c;
        a = (1LL * a * a) % c;
        b >>= 1;
    }
    return ret;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    cout << dpow(a % c, b);
    return 0;
}