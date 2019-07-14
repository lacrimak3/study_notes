#include <iostream>
using namespace std;

long long st[1001];
int top;
char a[100001][5];
int b[100001];
int len = 0;
template <typename It>
void _swap(It &a, It &b){
    It c(a); a = b; b = c;
}
int _strcmp(const char *s1, const char *s2){
    while(*s1 && *s2){
        if(*s1 != *s2) return (*s1 < *s2) ? -1 : 1;
        s1++; s2++;
    }
    if(*s1 != *s2) return (*s1 < *s2) ? -1 : 1;
    return 0;
}
long long _abs(long long n){
    return (n < 0) ? -n : n;
}
void solve(){
    top = 0;
    int v;
    cin >> v;
    st[top++] = v;
    for(int i = 0; i < len - 1; i++){
        if(!_strcmp(a[i], "NUM")) st[top++] = b[i];
        else{
            if(top < 1){
                cout << "ERROR\n";
                return;
            }
            if(!_strcmp(a[i], "POP")) top--;
            else if(!_strcmp(a[i], "INV")) st[top - 1] = -st[top - 1];
            else if(!_strcmp(a[i], "DUP")){
                st[top] = st[top - 1];
                top++;
            }
            else{
                if(top < 2){
                    cout << "ERROR\n";
                    return;
                }
                if(!_strcmp(a[i], "SWP")) _swap(st[top - 2], st[top - 1]);
                else if(!_strcmp(a[i], "ADD")){
                    st[top - 2] = st[top - 1] + st[top - 2];
                    top--;
                    if(_abs(st[top - 1]) > 1e9){
                        cout << "ERROR\n";
                        return;
                    }
                }
                else if(!_strcmp(a[i], "SUB")){
                    st[top - 2] = st[top - 2] - st[top - 1];
                    top--;
                    if(_abs(st[top - 1]) > 1e9){
                        cout << "ERROR\n";
                        return;
                    }
                }
                else if(!_strcmp(a[i], "MUL")){
                    st[top - 2] = st[top - 2] * st[top - 1];
                    top--;    
                    if(_abs(st[top - 1]) > 1e9){
                        cout << "ERROR\n";
                        return;
                    }
                }
                else{
                    if(st[top - 1] == 0){
                        cout << "ERROR\n";
                        return;
                    }
                    long long x = st[top - 2], y = st[top - 1];
                    if(!_strcmp(a[i], "DIV")){
                        st[top - 2] = _abs(x) / _abs(y);
                        top--;
                        if((x < 0 && y > 0) || (x > 0 && y < 0)) st[top - 1] = -st[top - 1];
                    }
                    else if(!_strcmp(a[i], "MOD")){
                        st[top - 2] = _abs(x) % _abs(y);
                        top--;
                        if(x < 0) st[top - 1] = -st[top - 1];
                    }
                    if(_abs(st[top - 1]) > 1e9){
                        cout << "ERROR\n";
                        return;
                    }
                }
            }
        }
    }
    if(top != 1){
        cout << "ERROR\n";
        return;
    }
    cout << st[0] << '\n';
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin >> a[len++];
        int now = len - 1;
        if(!_strcmp(a[now], "QUIT")) break;
        else if(!_strcmp(a[now], "END")){
            int n;
            cin >> n;
            while(n--) solve();
            len = 0;
            cout << '\n';
        }
        else if(!_strcmp(a[now], "NUM")){
            cin >> b[now];
        }
    }
    return 0;
}