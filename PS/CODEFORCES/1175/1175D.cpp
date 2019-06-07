#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long a[300001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = n; i > 1; i--)
        a[i - 1] += a[i];
    long long ans = a[1];
    sort(a + 2, a + n + 1);
    reverse(a + 2, a + n + 1);
    for(int i = 2; i <= k; i++)
        ans += a[i];
    cout << ans << '\n';    
    return 0;
}