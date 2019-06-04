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
    bool odd = false;
    bool even = false;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2) odd = true;
        else even = true;
    }
    if(odd && even) sort(a, a + n);
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}