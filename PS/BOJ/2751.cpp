#include <iostream>
using namespace std;

int a[1000001], b[1000001];
template <typename T>
void mergeSort(T begin, T end){
    if(begin == end || (end - begin == 1)) return;
    T mid = begin + (end - begin) / 2;
    mergeSort(begin, mid);
    mergeSort(mid, end);
    T s1 = begin, s2 = mid;
    int i;
    for(i = 0; s1 != mid && s2 != end; i++){
        if(*s1 < *s2){
            b[i] = *s1;
            s1++;
        }
        else{
            b[i] = *s2;
            s2++;
        }
    }
    while(s1 != mid){
        b[i++] = *s1;
        s1++;
    }
    while(s2 != end){
        b[i++] = *s2;
        s2++;
    }
    T cur = begin;
    for(i = 0; cur != end; i++, cur++){
        *cur = b[i];
    }
}

int n;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, a + n);
    for(int i = 0; i < n; i++) cout << a[i] << '\n';
    return 0;
}