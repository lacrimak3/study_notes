#include <iostream>
using namespace std;
const int HASH_SIZE = 10000;
const int PN = 23;

int T;
int n;
int table[HASH_SIZE][10];
char str[10001][11];
int lt[10001];
unsigned int genKey(const char *s){
    unsigned int key = 0, p = 1;
    for(int i = 0; s[i] != 0; i++){
        key += s[i] * p;
        p *= PN;
    }
    return key % HASH_SIZE;
}

template <typename It, typename Comp>
void _sort(It begin, It end, Comp cmp){
    if(begin == end) return;
    _swap(*begin, *((end - begin) / 2 + begin));
    It pi = begin;
    It le = begin + 1;
    It ri = end - 1;
    while(le <= ri){
        while(le <= ri && !cmp(pi, le)) le++;
        while(le <= ri && !cmp(ri, pi)) ri--;
        if(le <= ri) _swap(*le, *ri);
    }
    _swap(*pi, *ri);
    _sort(begin, ri);
    _sort(ri + 1, end);
}

int _strcmp(const char *s1, const char *s2){
    while(*s1 && *s2){
        if(*s1 != *s2) return (*s1 < *s2) ? -1 : 1;
        s1++; s2++;
    }
    if(*s1 != *s2) return (*s1 < *s2) ? -1 : 1;
    return 0;
}

bool cmp(int a, int b){
    return _strcmp(str[a], str[b]) <= 0;
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--){
        for(int i = 0; i < HASH_SIZE; i++) table[i][0] = 0;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> str[i];
            lt[i] = i;
        }
        sort(lt, lt + n, cmp);
        char t[51];
        bool ok = true;
        for(int i = 0; i < n && ok; i++){
            int idx = lt[i];
            t[0] = 0;
            for(int j = 0; str[idx][j] != 0 && ok; j++){
                t[j] = str[idx][j];
                t[j + 1] = 0;
                int key = genKey(t);
                int &size = table[key][0];
                if(size){
                    for(int k = 1; k <= size; k++){
                        if(_strcmp(str[table[key][k]], t) == 0){
                            ok = false;
                            break;
                        }
                    }
                }
                if(str[idx][j + 1] == 0){
                    size++;
                    table[key][size] = idx;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}