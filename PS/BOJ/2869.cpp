#include <iostream>
using namespace std;
using ll = long long;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, v;
    cin >> a >> b >> v;
    int ans = (v - a) / (a - b);
    if((v - a) % (a - b)) ans++;
    cout << ans + 1;
    return 0;
}