#include <bits/stdc++.h>
using namespace std;
const long long SIZE = 10000001;
long long a, b;
bool check[SIZE];
vector<long long> prime;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prime.reserve(664580);
    for(long long i = 2; i <= SIZE; i++){
        if(check[i]) continue;
        prime.push_back(i);
        for(long long j = i * i; j <= SIZE; j += i){
            check[j] = 1;
        }
    }
    cin >> a >> b;
    int ans = 0;
    for(const long long &i : prime){
        long long tmp = i;
        while(tmp <= b / i){
            tmp *= i;
            if(tmp >= a) ans++;
        }
    }
    cout << ans;
    return 0;
}