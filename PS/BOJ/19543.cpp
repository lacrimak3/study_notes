#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string block[26];
vector<int> ub[26];
int d[26][200001];
string dun;
long long solve(int blockCnt, int s, int e) {
    if (blockCnt < 0) return 0;
    int blockIdx = dun[blockCnt] - 'A';
    long long ret = e - s + 1;
    if (blockCnt == 0) return ret;
    int nxtIdx = dun[blockCnt - 1] - 'A';
    if(ub[nxtIdx].size() == 0) return ret;
    int ss = lower_bound(ub[nxtIdx].begin(), ub[nxtIdx].end(), s) - ub[nxtIdx].begin();
    int ee = upper_bound(ub[nxtIdx].begin(), ub[nxtIdx].end(), e) - ub[nxtIdx].begin() - 1;
    if (ss == ub[nxtIdx].size()) return ret;
    if(ub[nxtIdx][ss] > e || ub[nxtIdx][ee] < s) return ret;
    int ns = ub[nxtIdx][ss] - d[nxtIdx][ub[nxtIdx][ss]];
    int ne = ub[nxtIdx][ee];
    return ret + solve(blockCnt - 1, ns, ne);
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> block[i];
        for (int j = 0; j < m; j++) {
            if (j > 0 && block[i][j - 1] == 'R')
                d[i][j] = d[i][j - 1] + 1;
            if (block[i][j] == 'U') {
                ub[i].push_back(j);
            }
        }
    }
    cin >> dun;
    int blockIdx = dun[dun.length() - 1] - 'A';
    int e = m - 1;
    int s = e - d[blockIdx][e];
    cout << solve(dun.length() - 1, s, e);
    return 0;
}