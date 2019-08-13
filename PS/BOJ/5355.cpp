#include <cstdio>

int main(void){
    int T;
    scanf("%d ", &T);
    while(T--){
        double t;
        char a[101];
        scanf("%lf %[^\n]", &t, a);
        for(int i = 0; a[i]; i++){
            if(a[i] == '@') t *= 3;
            else if(a[i] == '%') t += 5;
            else if(a[i] == '#') t -= 7;
        }
        printf("%.2f\n", t);
    }
    return 0;
}