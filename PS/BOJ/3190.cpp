#include <bits/stdc++.h>
using namespace std;

int n, k, l;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int way;
int board[101][101];
pair<int, char> change[101];
queue<pair<int, int>> snake;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0, x, y; i < k; i++){
        cin >> x >> y;
        board[x - 1][y - 1] = 2;
    }
    cin >> l;
    for(int i = 0; i < l; i++) cin >> change[i].first >> change[i].second;
    snake.push({0, 0});
    int ans = 0, ch = 0;
    int x = 0, y = 0;
    while(1){
        int nx = x + dx[way], ny = y + dy[way];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 1){
            ans++;
            break;
        }
        snake.push({nx, ny});
        if(board[nx][ny] != 2){
            auto &[lx, ly] = snake.front();
            board[lx][ly] = 0;
            snake.pop();
        }
        board[nx][ny] = 1;

        ans++;
        x = nx, y = ny;
        if(ch < l && ans == change[ch].first){
            if(change[ch].second == 'L') way = (way + 3) % 4;
            else way = (way + 1) % 4;
            ch++;
        }
    }

    cout << ans;
    return 0;
}