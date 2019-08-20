#include <iostream>
using namespace std;

int n, m;
int a[8];
void permu(int idx, int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++) cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = idx; i <= n; i++){
        a[cnt] = i;
        permu(i + 1, cnt + 1);
    }
}

int main(void){
    cin >> n >> m;
    permu(1, 0);
    return 0;
}