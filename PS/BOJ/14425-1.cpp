#include <iostream>
using namespace std;
const int HASH_SIZE = 10000;
const int PN = 23;

int n, m, ans;
unsigned int makeHash(char *s){
    unsigned int key = 0, p = 1;
    for(int i = 0; s[i] != 0; i++){
        key += (s[i] * p);
        p *= PN;
    }
    return key % HASH_SIZE;
}
int _strcmp(const char *s1, const char *s2){
    while(*s1 && *s2){
        if(*s1 != *s2) return (*s1 < *s2) ? -1 : 1;
        s1++; s2++;
    }
    if(*s1 != *s2) return (*s1 < *s2) ? -1 : 1;
    return 0;
}
int table[HASH_SIZE][10];
char str[10001][501];
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> str[i];
        int key = makeHash(str[i]);
        int &size = table[key][0];
        size++;
        table[key][size] = i;
    }
    for(int i = 0; i < m; i++){
        char s[501];
        cin >> s;
        int key = makeHash(s);
        int &size = table[key][0];
        if(size){
            for(int j = 1; j <= size; j++){
                if(_strcmp(s, str[table[key][j]]) == 0){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}