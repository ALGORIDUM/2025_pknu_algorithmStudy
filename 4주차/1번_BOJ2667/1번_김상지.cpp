// bfs
#include<bits/stdc++.h>
using namespace std;

int n;
int board[26][26] ={0, };
int vis[26][26]={0, };
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
vector<int> line;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<n; j++){
            board[i][j] = s[j] - '0';
        }
    }
    int cnt=0;
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 0 이거나 방문했다면 
            if(!board[i][j]||vis[i][j])continue;
            q.push({i,j});
            vis[i][j] = 1;
            cnt++;
            int num =0;
            while(!q.empty()){
                pair<int,int> cur = q.front();
                q.pop();
                num++;
                for(int dir =0; dir<4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                    if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                    if(vis[nx][ny] || !board[nx][ny]) continue;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            line.push_back(num);
        }
    }
    cout<< cnt <<'\n';
    sort(line.begin(), line.end());
    for(auto c : line){
        cout<<c<<'\n';
    }
}