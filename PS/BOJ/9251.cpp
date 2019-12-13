#include <bits/stdc++.h>
using namespace std;

int d[1001][1001];
string s1, s2;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    for(int i = 1; i < s1.length(); i++){
        for(int j = 1; j < s2.length(); j++){
            if(s1[i] == s2[j]) d[i][j] = d[i - 1][j - 1] + 1;
            else{
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            }
        }
    }
    cout << d[s1.length() - 1][s2.length() - 1];
    return 0;
}