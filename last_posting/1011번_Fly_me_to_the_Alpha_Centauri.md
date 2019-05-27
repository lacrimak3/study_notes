# 1011번 Fly me to the Alpha Centauri
>https://www.acmicpc.net/problem/1011

## 문제
우주선에 공간이동 장치가 탑재되어 있다. 이 공간이동 장치는 이동 거리를 급격하게 늘릴 경우 기계에 심각한 결함이 발생하는 단점이 있어서, 이전 작동시기에 k광년을 이동했을 때는 k - 1, k, k + 1광년만을 다시 이동 할 수 있다.  
공간이동 장치는 에너지 소모가 크기 때문에 x지점에서 y지점까지 최소한의 작동 횟수로 이동해야 한다. 하지만 y지점에 도착해서도 공간 이동장치의 안정성을 위해 y지점에 도착하기 바로 직전의 이동거리는 1광년이어야 한다.  
x지점에서 y지점으로 이동하는데 필요한 공간 이동 장치 작동 횟수의 최솟값을 구하는 프로그램을 작성하라.

## 입력
첫 줄에 테스트 케이스의 개수 T가 주어진다. 각각의 테스트 케이스에 대해 현재 위치 x와 목표 위치 y가 정수로 주어지며, x는 y보다 작은 값을 갖는다. (0 <= x < y < 2^31)

## 풀이
직접 최소 작동횟수를 몇번 구해보면 규칙이 있음을 발견할 수 있다.  
n = y - x이고 k = sqrt(n이상의 최소 제곱수)라고 할 때  
n이 k * (k - 1)이하이면 2 * (k - 1)을 그 외엔 1을 더해서 출력하면 된다.  

```cpp
#include <iostream>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        int n = y - x;
        long long k = 1;
        for (k = 1; k*k < n; ++k);
        if (n <= (k * (k - 1)))
            cout << 2 * (k - 1) << '\n';
        else
            cout << 2 * k - 1 << '\n';
    }
    return 0;
}
```