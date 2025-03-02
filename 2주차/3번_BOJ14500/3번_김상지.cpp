#include<bits/stdc++.h>
using namespace std;

int n, m;
int v[505][505]={0,};
bool vis[505][505];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int total= 0;;

void dfs(int a, int b, int num, int sum){
    if(num == 4){
        total = max(sum, total);
        return;
    }
    if(!vis[a][b]){
        sum+=v[a][b];
        for(int i=0; i<4; i++){
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            vis[a][b] = 1;
            dfs(nx, ny, num+1, sum);
            vis[a][b] = 0;
        }
        
    }
    // ㅗㅓㅏㅜ 탐색 
    int s=0;
    for(int i=0; i<4; i++){
        s+=v[a][b];
        for(int j=0; j<4; j++){
            if(j==i) continue;
            int nx = a + dx[j];
            int ny = b + dy[j];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            s+=v[nx][ny];
        }
        total = max(total, s);
        s=0;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }
    for(int i =0; i<n; i++){
        for(int j=0; j<m; j++){
            dfs(i,j,0,0);
        }
    }
    cout<<total;
}