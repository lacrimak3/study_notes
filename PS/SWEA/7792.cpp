#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
 
int T;
int cntAlpha(string &s);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int n;
        cin >> n;
        vector<string> a(n);
        getline(cin, a[0]);
        for(int i = 0; i < n; i++) getline(cin, a[i]);
        sort(a.begin(), a.end());
        string ans = "";
        int ans_cnt = 0;
        for(int i = 0; i < n; i++){
            int cnt = cntAlpha(a[i]);
            if(cnt > ans_cnt){
                ans_cnt = cnt;
                ans = a[i];
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}
 
int cntAlpha(string &s){
    int a[26] = {0};
    for(char c : s){
        if(c < 'A' || c > 'Z') continue;
        a[c - 'A']++;
    }
    int ret = 0;
    for(int i = 0; i < 26; i++) if(a[i]) ret++;
    return ret;
}