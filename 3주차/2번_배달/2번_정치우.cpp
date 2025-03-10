#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define NODESIZE 55

int d[NODESIZE];
vector<pii> adj[NODESIZE];
priority_queue<pii, vector<pii>, greater<>> pq;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for(auto i: road) 
        adj[i[0]].push_back({i[2], i[1]}), adj[i[1]].push_back({i[2], i[0]});
    fill(d, d+NODESIZE, 1e9);
    d[1] = 0;
    pq.push({d[1], 1});
    while(!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        if(d[now.second] != now.first) continue;
        for(auto nxt: adj[now.second]) {
            if(d[nxt.second] <= d[now.second] + nxt.first) continue;
            d[nxt.second] = d[now.second] + nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }
    for(int i=1;i<=N;i++) if(d[i] <= K) ++answer;
    return answer;
}
