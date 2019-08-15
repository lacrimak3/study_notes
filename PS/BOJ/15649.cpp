#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

int n, m;
int a[9];
bool v[9];
void solve(int num, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++)
            cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(v[i]) continue;
        v[i] = true;
        a[cnt] = i;
        solve(i + 1, cnt + 1);
        v[i] = false;
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    solve(1, 0);
    return 0;
}