#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int a[13], ans[6];
bool visit[13];
void dfs(int now, int cnt);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        memset(visit, 0, sizeof(visit));
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        dfs(0, 0);
        cout << '\n';
    }
    return 0;
}

void dfs(int now, int cnt){
    if(cnt == 6){
        for(int i = 0; i < 6; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = now; i < n; i++){
        if(visit[i]) continue;
        visit[i] = true;
        ans[cnt] = a[i];
        dfs(i + 1, cnt + 1);
        visit[i] = false;
    }
}