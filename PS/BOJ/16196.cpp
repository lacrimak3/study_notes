#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

string s;
int n;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> n;
    string code = s.substr(0, 6);
    bool err = true;
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        if(t == code){
            err = false;
            break;
        }
    }

    int y = stoi(s.substr(6, 4)), m = stoi(s.substr(10, 2)), d = stoi(s.substr(12, 2));
    if(y < 1900 || y > 2011) err = true;
    if(m < 1 || m > 12) err = true;
    if(y == 2000 || (y % 4 == 0 && y % 100 != 0)) month[2]++;
    if(err || d < 1 || d > month[m]) err = true;

    int mf = stoi(s.substr(14, 3)) % 2;
    if(stoi(s.substr(14, 3)) == 0) err = true;
    int checksum = 0;
    for(int i = 0; i < 17; i++){
        checksum += s[i] - '0';
        checksum = (checksum * 2) % 11;
    }
    int x = (s[17] == 'X') ? 10 : s[17] - '0';
    if((checksum + x) % 11 != 1) err = true;
    if(err) cout << "I";
    else if(mf == 1) cout << "M";
    else cout << "F";
    return 0;
}