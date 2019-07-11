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