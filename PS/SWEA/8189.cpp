#include <iostream>
using namespace std;

int T;
int ans[101];
int n, a, b;
int t[101];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int tc = 1; tc <= T; ++tc){
        cin >> n >> a >> b;
        int cnt = 0, lidx = 0;
        for(int i = 0; i < n; i++){
            cin >> t[i];
            while(t[i] > t[lidx] + b && lidx < i){
                int ncnt = cnt + 1 >> 1;
                for(int j = lidx; j < lidx + ncnt; j++){
                    ans[j] = t[lidx] + b;
                }
                lidx = lidx + ncnt;
                cnt -= ncnt;
            }
            cnt++;
            int ncnt = cnt + 1 >> 1;
            if(t[i] == t[lidx] + b){
                for(int j = lidx; j < lidx + ncnt; j++){
                    ans[j] = t[i];
                }
                lidx = lidx + ncnt;
                cnt -= ncnt;
            }
            if(cnt >= a){
                for(int j = lidx; j < lidx + ncnt; j++){
                    ans[j] = t[i];
                }
                lidx = lidx + ncnt;
                cnt -= ncnt;
            }
        }
        while(cnt){
            int ncnt = cnt + 1 >> 1;
            for(int i = lidx; i < lidx + (cnt + 1) / 2; i++){
                ans[i] = t[lidx] + b;
            }
            lidx = lidx + ncnt;
            cnt -= ncnt;
        }
        cout << '#' << tc << ' ';
        for(int i = 0; i < n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}