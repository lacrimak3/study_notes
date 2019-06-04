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
const long long LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int n;
int a[100001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        if(!a[i]){
            cnt++;
            for(int j = i; j <= n; j += i)
                a[j] = cnt;
        }
    }
    for(int i = 2; i <= n; i++)
        cout << a[i] << ' ';
    return 0;
}