#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int SIZE = 2001;
int T;
int ans;
int n, sum, a[SIZE];
int v[SIZE];
bool solve(int idx, int ps, int num); 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        memset(v, 0, sizeof(v));
        sum = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        sort(a, a + n);
        reverse(a, a + n);
        solve(0, 0, 1);
        solve(0, 0, 2);
        cout << '#' << tc << '\n';
        for(int i = 0; i < n; i++)
            if(v[i] == 0) cout << a[i] << ' ';
        cout << '\n';
        for(int i = 0; i < n; i++)
            if(v[i] == 1) cout << a[i] << ' ';
        cout << '\n';
        for(int i = 0; i < n; i++)
            if(v[i] == 2) cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}

bool solve(int idx, int ps, int num){
    if(idx >= n || ps > sum / 3) return false;
    if(ps == sum / 3) return true;
    bool ret = false;
    if(v[idx] == 0){
        v[idx] = num;
        if(ret = solve(idx + 1, ps + a[idx], num)) return ret;
        v[idx] = 0;
    }
    return ret = solve(idx + 1, ps, num);
}