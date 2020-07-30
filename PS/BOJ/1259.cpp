#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    while (1) {
        cin >> s;
        if (s[0] == '0') break;
        int i = 0;
        for (i = 0; i < (s.length() / 2); i++) {
            if (s[i] != s[s.length() - 1 - i]) break;
        }
        if (i == s.length() / 2)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}