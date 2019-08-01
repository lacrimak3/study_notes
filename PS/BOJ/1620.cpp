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

int n, m;
unordered_map<string, int> poke_map;
string poke[100001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        poke_map[t] = i + 1;
        poke[i + 1] = t;
    }
    for(int i = 0; i < m; i++){
        string t;
        cin >> t;
        if(t[0] >= '0' && t[0] <= '9'){
            int num = stoi(t);
            cout << poke[num] << '\n';
        }
        else{
            cout << poke_map[t] << '\n';
        }
    }
    return 0;
}