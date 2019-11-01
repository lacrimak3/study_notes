#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> ans;
void solve(int n, int s, int e){
    if(n == 1){
        ans.emplace_back(s, e);
        return;
    }
    int nxt = 6 - (s + e);
    solve(n - 1, s, nxt);
    ans.emplace_back(s, e);
    solve(n - 1, nxt, e);
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve(n, 1, 3);
    cout << ans.size() << '\n';
    for(const auto &[x, y] : ans)
        cout << x << ' ' << y << '\n';
    return 0;
}