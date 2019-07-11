#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct _string{
    char s[51];
    int len;
    bool operator < (const _string &other) const {
        if(len == other.len){
            int i = 0;
            for(; s[i] != 0 && other.s[i] != 0; i++){
                if(s[i] != other.s[i]) return s[i] < other.s[i];
            }
            if(other.s[i]) return true;
            return false;
        }
        else return len < other.len;
    }
    void inp(){
        cin >> s;
        for(len = 0; s[len] != 0; len++);
    }
};

template <typename It>
void _swap(It &a, It &b){
    It c(a); a = b; b = c;
}

template <typename It>
void _quick_sort(It begin, It end){
    if(begin == end) return;
    _swap(*begin, *(begin + (end - begin) / 2));
    It pi = begin;
    It le = begin + 1;
    It ri = end - 1;
    while(le <= ri){
        while(le <= ri && !(*pi < *le)) le++;
        while(le <= ri && !(*ri < *pi)) ri--;
        if(le <= ri) _swap(*le, *ri);
    }
    _swap(*pi, *ri);
    _quick_sort(begin, ri);
    _quick_sort(ri + 1, end);
}

int T;
int ans;
int n;
_string a[20001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        cin >> n;
        for(int i = 0; i < n; i++) a[i].inp();
        _quick_sort(a, a + n);
        cout << '#' << tc << '\n';
        for(int i = 0; i < n; i++){
            if(i != n - 1){
                if(!(a[i] < a[i + 1])) continue;
            }
            cout << a[i].s << '\n';
        }
    }
    return 0;
}