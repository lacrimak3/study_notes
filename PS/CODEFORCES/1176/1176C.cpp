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

const int SIZE = 500001;
int n;
int a[SIZE];
int b[6];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 4) b[0]++;
        else if(a[i] == 8){
            if(b[0] > b[1]) b[1]++;
        }
        else if(a[i] == 15){
            if(b[1] > b[2]) b[2]++;
        }
        else if(a[i] == 16){
            if(b[2] > b[3]) b[3]++;
        }
        else if(a[i] == 23){
            if(b[3] > b[4]) b[4]++;
        }
        else{
            if(b[4] > b[5]) b[5]++;
        }
    }
    cout << n - b[5] * 6;
    return 0;
}