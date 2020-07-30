#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[200001];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a, a + n);
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        int s = a[i].first, t = a[i].second;
        if(pq.size() && -pq.top() <= s) {
            pq.pop();
        }
        pq.push(-t);
    }
    cout << pq.size();
    return 0;
}