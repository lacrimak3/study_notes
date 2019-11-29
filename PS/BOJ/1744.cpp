#include <bits/stdc++.h>
using namespace std;

int n, z, ans;
vector<int> m, p;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    m.reserve(n);
    p.reserve(n);
    for(int i = 0, x; i < n; i++){
        cin >> x;
        if(x < 0) m.push_back(x);
        else if(x > 1) p.push_back(x);
        else if(x == 1) ans++;
        else z++;
    }
    sort(m.begin(), m.end());
    sort(p.rbegin(), p.rend());
    if(z && m.size() % 2) m.push_back(0);
    if(m.size() % 2) m.push_back(1);
    if(p.size() % 2) p.push_back(1);
    for(int i = 0; i < p.size(); i += 2)
        ans += p[i] * p[i + 1];
    for(int i = 0; i < m.size(); i += 2)
        ans += m[i] * m[i + 1];
    cout << ans;
    return 0;
}