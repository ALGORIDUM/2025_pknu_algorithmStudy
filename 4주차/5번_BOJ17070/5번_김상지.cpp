// 파이프 옮기기 
#include<bits/stdc++.h>
using namespace std;

int n, board[17][17];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ;
    for(int i=1; i<=n; i++){
        for(int j =1; j<=n; j++){
            cin >> board[i][j];
        }
    }
    queue<tuple<int, int,int>> q;
    q.push({1,2,0});
    int cnt=0; 
    while(!q.empty()){
        auto [x,y,d]= q.front();
        // d =0 가로, d=1 세로, d=2 대각선 
        q.pop();
        if(x == n && y == n){
            cnt++;
            continue;
        }
        // 가로 
        if(d == 0 || d == 2){ // 가로거나 대각선 
            int nx = x;
            int ny = y+1;
            if(nx<1 || nx>n ||ny<1 ||ny>n|| board[nx][ny]);
            else q.push({nx, ny, 0});
        }
        // 세로 
        if(d == 1 || d == 2){ // 세로거나 대각선 
            int nx = x+1;
            int ny = y;
            if(nx<1 || nx>n ||ny<1 ||ny>n|| board[nx][ny]);
            else q.push({nx, ny, 1});
        }
        // 대각선 
        {
            int nx = x+1;
            int ny = y+1;
            if(nx>n ||ny>n|| board[nx][ny]);
            else if(board[nx-1][ny]||board[nx][ny-1]);
            else q.push({nx, ny, 2});
        }
    }
    cout<<cnt;
}