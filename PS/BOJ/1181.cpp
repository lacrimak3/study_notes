#include <bits/stdc++.h>
using namespace std;

int n;
string a[20001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, 
    [](const string &s1, const string &s2) -> bool{
        if(s1.length() == s2.length()) return s1 < s2;
        else return s1.length() < s2.length();
    });
    for(int i = 0; i < n; i++){
        if(i != 0 && a[i - 1] == a[i]) continue;
        cout << a[i] << '\n';
    }
    return 0;
}