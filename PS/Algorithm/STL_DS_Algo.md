# STL에서 자주 사용하는 자료구조/알고리즘 구현


## pair

```cpp
template <typename A, typename B>
class _pair{
public:
    A x; B y;
    _pair(A a, B b) : x(a), y(b){}
    _pair(){}
    bool operator < (const _pair &other) const{
        if(x == other.x) return y < other.y;
        else return x < other.y;
    }
};
```

## swap

```cpp
template <typename It>
void _swap(It &a, It &b){
    It c(a); a = b; b = c;
}
```

## quick_sort

```cpp
template <typename It>
void _sort(It begin, It end){
    if(begin == end) return;
    _swap(*begin, *((end - begin) / 2 + begin));
    It pi = begin;
    It le = begin + 1;
    It ri = end - 1;
    while(le <= ri){
        while(le <= ri && !(*pi < *le)) le++;
        while(le <= ri && !(*ri < *pi)) ri--;
        if(le <= ri) _swap(*le, *ri);
    }
    _swap(*pi, *ri);
    _sort(begin, ri);
    _sort(ri + 1, end);
}
```