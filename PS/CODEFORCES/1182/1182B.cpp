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

const int N = 501;
int n, m;
string a[N];
bool v[N][N];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j < m - 1; j++){
            if(a[i][j] == '*' && a[i - 1][j] == '*' && a[i + 1][j] == '*' && a[i][j - 1] == '*' && a[i][j + 1] == '*'){
                int ue = i, de = i, le = j, re = j;
                while(ue >= 0 && a[ue][j] == '*') v[ue--][j] = true;
                while(de < n && a[de][j] == '*') v[de++][j] = true;
                while(le >= 0 && a[i][le] == '*') v[i][le--] = true;
                while(re < m && a[i][re] == '*') v[i][re++] = true;
                for(int x = 0; x < n; x++){
                    for(int y = 0; y < m; y++){
                        if(!v[x][y] && a[x][y] == '*'){
                            cout << "NO";
                            return 0;
                        }
                    }
                }
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}