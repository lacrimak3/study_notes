#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
char a[16];
char ans[16];
void dfs(int now, int cnt);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    dfs(0, 0);
    return 0;
}

void dfs(int now, int cnt){
    if(cnt == m){
        int mo = 0, ja = 0;
        for(int i = 0; i < m; i++){
            if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') mo++;
        }
        ja = m - mo;
        if(mo < 1 || ja < 2) return;
        cout << ans << '\n';
        return;
    }
    for(int i = now; i < n; i++){
        ans[cnt] = a[i];
        dfs(i + 1, cnt + 1);
    }
}