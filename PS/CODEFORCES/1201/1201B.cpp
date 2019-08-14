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
using ll = long long;
int n;
int a[100001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    if(sum % 2){
        cout << "NO\n";
        return 0;
    }
    sort(a, a + n);
    if(sum - a[n - 1] < a[n - 1]){
        cout << "NO\n";
    }
    else cout << "YES\n";
    return 0;
}