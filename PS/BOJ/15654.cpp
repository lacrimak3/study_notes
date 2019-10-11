#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int n, m;
int a[8], ans[8];
bool visit[8];
void dfs(int now, int cnt);
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    dfs(0, 0);
    return 0;
}

void dfs(int now, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 0; i < n; i++){
        if(visit[i]) continue;
        visit[i] = true;
        ans[now] = a[i];
        dfs(now + 1, cnt + 1);
        visit[i] = false;
    }
}