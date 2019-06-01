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
#include <unordered_map>
#include <vector>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int TC, k;
int a[1000];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int len = 0;
    a[len] = 1;
    for(len = 1; len < 1000; len++){
         a[len] = a[len - 1] + (len + 1);
         if(a[len] > 1000) break;
    }
    cin >> TC;
    int t = 0;
    while(t++ < TC){
        int x;
        cin >> x;
        bool ok = false;
        for(int i = 0, j, k; i < len; i++){
            for(j = 0; j < len; j++){
                for(k = 0; k < len; k++)
                    if(a[i] + a[j] + a[k] == x){
                        ok = true;
                        break;
                    }
                if(k != len) break;
            }
            if(j != len) break;
        }
        if(ok) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}