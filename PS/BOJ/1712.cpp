#include <iostream>
using namespace std;
using ll = long long;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    if(c <= b){
        cout << -1;
    }
    else{
        cout << a / (c - b) + 1;
    }
    return 0;
}