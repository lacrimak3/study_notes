#include <bits/stdc++.h>
using namespace std;

bool mi;
int ans, n;
char op;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> ans;
    while(cin >> op){
        if(op == '-') mi = true;
        cin >> n;
        if(mi) ans -= n;
        else ans += n;
    }
    cout << ans;
    return 0;
}