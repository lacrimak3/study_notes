#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int T;
vector<int> pal;
bool checkPal(int x);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    pal.push_back(0);
    for(int i = 1; i < 10000; i++){
        if(checkPal(i)) pal.push_back(i);
    }
    cin >> T;
    int n;
    for (int tc = 1; tc <= T; ++tc) {
        cin >> n;
        vector<int> ans;
        for(int i = 0, j, k; i < pal.size(); i++){
            for(j = 0; j < pal.size(); j++){
                for(k = 0; k < pal.size(); k++){
                    if(pal[i] + pal[j] + pal[k] == n){
                        if(pal[i] != 0) ans.push_back(pal[i]);
                        if(pal[j] != 0) ans.push_back(pal[j]);
                        if(pal[k] != 0) ans.push_back(pal[k]);
                        break;
                    }
                }
                if(k != pal.size()) break;
            }
            if(k != pal.size()) break;
        }
        cout << "Case #" << tc << '\n';
        cout << ans.size() << ' ';
        for(int i : ans) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}

bool checkPal(int x){
    int t[4];
    int len = 0;
    for(; x; len++){
        t[len] = x % 10;
        x /= 10;
    }
    len--;
    for(int i = 0; i <= len / 2; i++){
        if(t[i] != t[len - i]) return false;
    }
    return true;
}