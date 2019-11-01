#include <bits/stdc++.h>
using namespace std;

int n, r, c;

int solve(int n, int x, int y){
    if(n == 1) return 0;
    int nxtN = n / 2;
    if(r < x + nxtN && c < y + nxtN)
        return solve(nxtN, x, y);
    if(r < x + nxtN && c >= y + nxtN)
        return solve(nxtN, x, y + nxtN) + nxtN * nxtN;
    if(r >= x + nxtN && c < y + nxtN)
        return solve(nxtN, x + nxtN, y) + 2 * nxtN * nxtN;
    if(r >= x + nxtN && c >= y + nxtN)
        return solve(nxtN, x + nxtN, y + nxtN) + 3 * nxtN * nxtN;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> r >> c;
    cout << solve(pow(2, n), 0, 0);
    return 0;
}