#include <bits/stdc++.h>
using namespace std;

int dx[]={-1,0,1,0},dy[]={0,-1,0,1};

int BFS(vector<string> &places) {
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++){
            if(places[i][j] == 'P') {
                queue<pair<int,int>> q;
                bool vis[5][5] = {0};
                q.push({i,j}), vis[i][j] = 1;
                for(int t=0;t<2;t++) {
                    int qs = q.size();
                    while(qs--) {
                        auto [x,y] = q.front();
                        q.pop();
                        for(int i=0;i<4;i++) {
                            int nx=x+dx[i],ny=y+dy[i];
                            if(nx<0||ny<0||nx>=5||ny>=5||vis[nx][ny]||places[nx][ny]=='X')continue;
                            if(places[nx][ny]=='P') return 0;
                            q.push({nx,ny}), vis[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto p:places) 
        answer.push_back(BFS(p));
    return answer;
}