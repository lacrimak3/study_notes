#include <cstring>
#include <iostream>
using namespace std;

int T;
int ans;
int n;
int book[200001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        ans = 0;
        memset(book, 0, sizeof(book));
        cin >> n;
        for(int i = 0, t; i < n; i++){
            cin >> t;
            if(book[t - 1] == 0){
                book[t] = t;
                ans++;
            }
            else{
                book[t] = book[t - 1];
                if(book[t - 1] == t - 1) book[t - 1] = t;
                else book[book[t - 1]] = t;
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}