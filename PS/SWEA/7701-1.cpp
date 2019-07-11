#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int T;
int ans;
int n;
string a[20001];
bool cmp(const string &x, const string &y);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, cmp);
        cout << '#' << tc << '\n';
        for(int i = 0; i < n; i++){
            if(i != n - 1 && a[i] == a[i + 1]) continue;
            cout << a[i] << '\n';
        }
    }
    return 0;
}

bool cmp(const string &x, const string &y){
    if(x.length() == y.length()) return x < y;
    else return x.length() < y.length();
}