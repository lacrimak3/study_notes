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

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a[9], sum = 0;
    for(int i = 0; i < 9; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + 9);
    for(int i = 0, j = 0; i < 9; i++){
        for(j = i + 1; j < 9; j++){
            if(sum - a[i] - a[j] == 100){
                a[i] = a[j] = -1;
                break;
            }
        }
        if(j != 9) break;
    }
    for(int i = 0; i < 9; i++)
        if(a[i] != -1) cout << a[i] << '\n';
    return 0;
}