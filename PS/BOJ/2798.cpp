#include <iostream>
using namespace std;
using ll = long long;

int n, m;
int a[101];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                int sum = a[i] + a[j] + a[k];
                if(sum <= m && sum > ans) ans = sum;
            }
        }
    }
    cout << ans;
    return 0;
}