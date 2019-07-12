#include <algorithm>
#include <iostream>
using namespace std;
const long long LINF = 1e18;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int T;
char s[40], ans[200];
char an[46] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ $%*+-./:";
char Hex[17] = "0123456789ABCDEF";
int bi[160], ans_len;
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        int len = 0, ai = 0, ans_len = 0;
        cin >> s;
        for(int i = 0; s[i] != 0; i++){
            int n;
            if(s[i] >= '0' && s[i] <= '9') n = s[i] - '0';
            else n = s[i] - 'A' + 10;
            for(int j = 0; j < 4; j++){
                if(n & (1 << j)) bi[len + 3 - j] = 1;
                else bi[len + 3 - j] = 0;
            }
            len += 4;
        }
        for(int idx = 0; idx < len - 4;){
            int mode = 0, cnt = 0;
            for(int i = 0; i < 4; i++){
                mode *= 2;
                mode += bi[idx++];
            }
            if(mode == 0) break;
            else if(mode == 1){
                for(int i = 0; i < 10; i++){
                    cnt *= 2;
                    cnt += bi[idx++];
                }
                ans_len += cnt;
                int n = 0;
                while(cnt >= 3){
                    for(int i = 0; i < 10; i++){
                        n *= 2;
                        n += bi[idx++];
                    }
                    for(int i = 0; i < 3; i++){
                        ans[ai + 2 - i] = (n % 10) + '0';
                        n /= 10;
                    }
                    ai += 3;
                    cnt -= 3;
                }
                if(cnt == 2){
                    for(int i = 0; i < 7; i++){
                        n *= 2;
                        n += bi[idx++];
                    }
                    for(int i = 0; i < 2; i++){
                        ans[ai + 1 - i] = (n % 10) + '0';
                        n /= 10;
                    }
                    ai += 2;
                }
                else if(cnt == 1){
                    for(int i = 0; i < 4; i++){
                        n *= 2;
                        n += bi[idx++];
                    }
                    ans[ai++] = n + '0';
                }
            }
            else if(mode == 2){
                for(int i = 0; i < 9; i++){
                    cnt *= 2;
                    cnt += bi[idx++];
                }
                ans_len += cnt;
                int n = 0;
                while(cnt >= 2){
                    n = 0;
                    for(int i = 0; i < 11; i++){
                        n *= 2;
                        n += bi[idx++];
                    }
                    ans[ai] = an[n / 45];
                    ans[ai + 1] = an[n % 45];
                    ai += 2;
                    cnt -= 2;
                }
                if(cnt > 0){
                    n = 0;
                    for(int i = 0; i < 6; i++){
                        n *= 2;
                        n += bi[idx++];
                    }
                    ans[ai++] = an[n];
                }
            }
            else if(mode == 4){
                for(int i = 0; i < 8; i++){
                    cnt *= 2;
                    cnt += bi[idx++];
                }
                ans_len += cnt;
                while(cnt--){
                    int n = 0;
                    for(int i = 0; i < 8; i++){
                        n *= 2;
                        n += bi[idx++];
                    }
                    if(n >= 0x20 && n <= 0x7e){
                        if(n == '\\' || n == '#'){
                            ans[ai++] = '\\';
                        }
                        ans[ai++] = n;
                    }
                    else{
                        ans[ai++] = '\\';
                        ans[ai] = Hex[n / 16];
                        ans[ai + 1] = Hex[n % 16];
                        ai += 2;
                    }
                }
            }
            else{
                for(int i = 0; i < 8; i++){
                    cnt *= 2;
                    cnt += bi[idx++];
                }
                ans_len += cnt;
                while(cnt--){
                    int n = 0;
                    for(int i = 0; i < 13; i++){
                        n *= 2;
                        n += bi[idx++];
                    }
                    if(n >= 0x20 && n <= 0x7e){
                        if(n == '\\' || n == '#'){
                            ans[ai++] = '\\';
                        }
                        ans[ai++] = n;
                    }
                    else{
                        ans[ai++] = '#';
                        ans[ai++] = n / 4096 + '0';
                        n %= 4096;
                        ans[ai++] = Hex[n / 256];
                        n %= 256;
                        ans[ai++] = Hex[n / 16];
                        n %= 16;
                        ans[ai++] = Hex[n];
                    }
                }
            }
        }
        ans[ai] = 0;
        cout << ans_len << ' ' << ans << '\n';
    }
    return 0;
}