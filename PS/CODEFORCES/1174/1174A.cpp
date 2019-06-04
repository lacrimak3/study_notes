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

int N;
int a[2000];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int s1 = 0, s2 = 0;
    for(int i = 0; i < 2 * N; i++){
        cin >> a[i];
        if(i < N) s1 += a[i];
        else s2 += a[i];
    }
    for(int i = 0, j; i < N; i++){
        for(j = N; j < 2 * N; j++){
            if(a[i] != a[j]){
                if(s1 - a[i] + a[j] != s2 - a[j] + a[i]){
                    s1 += -a[i] + a[j];
                    s2 += -a[j] + a[i];
                    swap(a[i], a[j]);
                    break;
                }
            }
        }
        if(j != 2 * N) break;
    }
    if(s1 != s2){
        for(int i = 0; i < 2 * N; i++)
            cout << a[i] << ' ';
    }
    else cout << -1;
    return 0;
}