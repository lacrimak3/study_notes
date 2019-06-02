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
string a[8] = {"WBWBWBWB", "BWBWBWBW", "WBWBWBWB", "BWBWBWBW","WBWBWBWB", "BWBWBWBW","WBWBWBWB", "BWBWBWBW"};
string b[50];
int n, m;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> b[i];
    int ans = INF;
    for(int I = 0; I <= n - 8; I++){
        for(int J = 0; J <= m - 8; J++){
            int t = 0;
            for(int i = I; i < I + 8; i++){
                for(int j = J; j < J + 8; j++){
                    if(b[i][j] != a[i - I][j - J]) t++;
                }
            }
            ans = min({ans, t, 64 - t});
        }
    }
    cout << ans << '\n';
    return 0;
}