#include <cstring>
#include <iostream>
using namespace std;

const int SIZE = 1000001;
int T;
int ans;
int l, r;
int a[SIZE];
bool p[SIZE];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2; i <= SIZE; i++){
        if(!p[i]){
            for(int j = i + i; j <= SIZE; j += i) p[j] = true;
        }
    }
    int c = 0;
    for(int i = 2; i <= SIZE; i++){
        if(i != 2 && i % 4 != 1) p[i] = true;
        if(!p[i]) c++;
        a[i] = c;
    }
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        cin >> l >> r;
        ans = a[r] - a[l - 1];
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}