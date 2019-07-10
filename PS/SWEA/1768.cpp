#define N 4

typedef struct {
    int strike;
    int ball;
} Result;
struct Number{
    int digits[4];
    Number(){}
    Number(int a, int b, int c, int d){
        digits[0] = a;
        digits[1] = b;
        digits[2] = c;
        digits[3] = d;
    }
};

Number num[10001], num2[10001];
int digits_u[10];
int len, len2, len3;
bool first = true;

extern Result query(int guess[]);
void doUserImplementation(int guess[]) {
    len = len3;
    if(first){
        first = false;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(i == j) continue;
                for(int k = 0; k < 10; k++){
                    if(i == k || j == k) continue;
                    for(int m = 0; m < 10; m++){
                        if(i == m || j == m || k == m) continue;
                        num[len++] = Number(i, j, k, m);
                    }
                }
            }
        }
        len3 = len;
    }
    for(int i = 0; i < 10; i++) digits_u[i] = 0;
    guess[0] = 0, guess[1] = 7, guess[2] = 1, guess[3] = 2;
    digits_u[0] = digits_u[1] = digits_u[2] = digits_u[7] = 1;
    unsigned int random = 34238423;
    bool fi = false;
    while(1){
        Result cur = query(guess), t;
        if(cur.strike == 4) break;
        len2 = 0;
        for(int i = 0; i < len; i++){
            t.strike = 0;
            t.ball = 0;
            if(!fi){
                for(int idx = 0; idx < N; idx++){
                    if(num[i].digits[idx] == guess[idx])
                        t.strike++;
                    else if(digits_u[num[i].digits[idx]] > 0)
                        t.ball++;
                }    
                if(t.strike == cur.strike && t.ball == cur.ball){
                    num2[len2++] = num[i];
                }
            }
            else{
                for(int idx = 0; idx < N; idx++){
                    if(num2[i].digits[idx] == guess[idx])
                        t.strike++;
                    else if(digits_u[num2[i].digits[idx]] > 0)
                        t.ball++;
                }
                if(t.strike == cur.strike && t.ball == cur.ball){
                    num2[len2++] = num2[i];
                }
            }
        }
        fi = true;
        int nxt = (random * len) % len2;
        random *= len;
        len = len2;
        for(int i = 0; i < 10; i++) digits_u[i] = 0;
        for(int i = 0; i < N; i++){
            guess[i] = num2[nxt].digits[i];
            digits_u[guess[i]] = 1;
        }
    }
}