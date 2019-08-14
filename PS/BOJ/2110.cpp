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
const int N = 200001;

int n, c;
int home[N];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i = 0; i < n; i++) cin >> home[i];
    sort(home, home + n);
    int l = 1, r = home[n - 1] - home[0] + 1;
    while(l < r){
        int m = l + r + 1 >> 1;
        int cnt = 1;
        int h = home[0];
        for(int i = 1; i < n; i++){
            if(home[i] >= h + m){
                cnt++;
                h = home[i];
            }
        }
        if(cnt >= c) l = m;
        else r = m - 1;
    }
    cout << r;
    return 0;
}