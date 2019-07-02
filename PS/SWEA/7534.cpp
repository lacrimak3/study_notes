#include <cstring>
#include <iostream>
using namespace std;

const int N = 100001;
int T;
int a[N];
char ans[N * 2];
int st[N], top;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        top = 0;
        int n;
        cin >> n;
        int k = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 1, j = 0; i <= n; i++){
            if(top == 0 || a[j] >= st[top - 1]){
                ans[k++] = '+';
                st[top++] = i;
            }
            while(j < n && a[j] == st[top - 1]){
                ans[k++] = '-';
                j++;
                top--;
            }
        }
        if(top != 0){
            ans[0] = 'N';
            ans[1] = 'O';
            k = 2;
        }
        ans[k] = 0;
        cout << '#' << tc << ' ';
        cout << ans << '\n';
    }
    return 0;
}