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

int N, ans;
string a[51];
void row(int x);
void col(int x);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> a[i];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1; j++){
            swap(a[j][i], a[j + 1][i]);
            row(j); row(j + 1); col(i);
            swap(a[j][i], a[j + 1][i]);
            swap(a[i][j], a[i][j + 1]);
            row(i); col(j); col(j + 1);
            swap(a[i][j], a[i][j + 1]);
        }
    }
    cout << ans;
    return 0;
}
void row(int x){
    for(int i = 1, t = 1; i < N; i++){
        if(a[x][i] != a[x][i - 1]) t = 0;
        t++;
        ans = max(ans, t);
    }
}

void col(int x){
    for(int i = 1, t = 1; i < N; i++){
        if(a[i][x] != a[i - 1][x]) t = 0;
        t++;
        ans = max(ans, t);
    }
}