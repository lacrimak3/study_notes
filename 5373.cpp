#include <iostream>
using namespace std;

char cube[6][3][3];
int dir[6][4] = {{3, 2, 4, 5}, {2, 3, 4, 5}, {0, 1, 4, 5}, {0, 1, 5, 4}, {0, 1, 3, 2}, {0, 1, 2, 3}};

int T;
void init(){
    for(int i = 0; i < 6; i++){
        char c;
        if(i == 0) c = 'w';
        else if(i == 1) c = 'y';
        else if(i == 2) c = 'r';
        else if(i == 3) c = 'o';
        else if(i == 4) c = 'g';
        else c = 'b';
        for(int j = 0; j < 3; j++)
            for(int k = 0; k < 3; k++)
                cube[i][j][k] = c;
    }
}
int changeNum(char c){
    int ret = -1;
    if(c == 'U') ret = 0;
    else if(c == 'D') ret = 1;
    else if(c == 'F') ret = 2;
    else if(c == 'B') ret = 3;
    else if(c == 'L') ret = 4;
    else ret = 5;
    return ret;
}
void turnRight(int n){
    char t[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            t[j][2 - i] = cube[n][i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cube[n][i][j] = t[i][j];
        }
    }
    if(n == 0){
        
    }
}
void turnLeft(int n){
    char t[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            t[j][i] = cube[n][i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cube[n][i][j] = t[i][j];
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    char op[3];
    while(T--){
        init();
        int n;
        cin >> n;
        while(n--){
            cin >> op;
            int num = changeNum(op[0]);
            if(op[1] == '+') turnRight(num);
            else turnLeft(num);
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                cout << cube[0][i][j];
            }
            cout << '\n';
        }
    }
}
