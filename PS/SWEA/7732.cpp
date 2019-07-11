#include <cstring>
#include <iostream>
using namespace std;
 
int T;
int ans;
int main(void) {
   scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        ans = 0;
        int h1, m1, s1, h2, m2, s2;
        scanf("%d:%d:%d", &h1, &m1, &s1);
        scanf("%d:%d:%d", &h2, &m2, &s2);
        s1 += m1 * 60 + h1 * 60 * 60;
        s2 += m2 * 60 + h2 * 60 * 60;
        if(s2 < s1) s2 += 86400;
        int h, m, s;
        s2 -= s1;
        h = s2 / 3600;
        s2 %= 3600;
        m = s2 / 60;
        s2 %= 60;
        s = s2;
        printf("#%d %02d:%02d:%02d\n", tc, h, m, s);
    }
    return 0;
}