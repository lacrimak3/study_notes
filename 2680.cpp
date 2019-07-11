#include <algorithm>
#include <iostream>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int T;
char s[40];
int bi[160];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        cin >> s;
        for(int i = 0; s[i] != 0; i++){
            int n;
            if(s[i] >= '0' && s[i] <= '9') n = s[i] - '0';
            else n = s[i] - 'A' + 10;
        }
    }
    return 0;
}
