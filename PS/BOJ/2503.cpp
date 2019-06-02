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
int a[100][3];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++)
            cin >> a[i][j];
    int ans = 0;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(i == j) continue;
            for(int k = 1; k <= 9; k++){
                if(i == k || j == k) continue;
                bool ok = true;
                for(int x = 0; x < N; x++){
                    int st = 0, ba = 0;
                    int b[3] = {a[x][0] / 100, (a[x][0] / 10) % 10, a[x][0] % 10};
                    int c[3] = {i, j, k};
                    for(int I = 0; I < 3; I++){
                        for(int J = 0; J < 3; J++){
                            if(I == J && b[I] == c[J]) st++;
                            else if(I != J && b[I] == c[J]) ba++;
                        }
                    }
                    if(st != a[x][1] || ba != a[x][2]){
                        ok = false;
                        break;
                    }
                }
                if(ok) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}