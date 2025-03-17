#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[2005];
int d[55];
const int INF = 0x3f3f3f3f;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(int i=0; i<road.size(); i++){
        int a=road[i][0];
        int b=road[i][1];
        int c=road[i][2]; // 거리
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    fill(d, d+N+1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    d[1]=0;
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(d[cur.second] != cur.first) continue;
        for(auto c : v[cur.second]){
            if(d[c.second] <= d[cur.second] + c.first) continue;
            d[c.second] = d[cur.second] + c.first;
            pq.push({d[c.second], c.second});
        }
    }
    int total = 0;
    for(int i=1; i<= N; i++){
        if(d[i]<=K) total++;
    }
    return total;
}