#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string n1, op, n2, ans = "1";
    cin >> n1 >> op >> n2;
    if(op == "*")
        ans.append(n1.length() + n2.length() - 2, '0');
    else{
        int len1 = n1.length(), len2 = n2.length();
        if(len2 > len1) swap(len1, len2);
        ans.append(len1 - 1, '0');
        ans[len1 - len2] = '1';
        if(len1 == len2) ans[0] = '2';
    }

    cout << ans;
    return 0;
}