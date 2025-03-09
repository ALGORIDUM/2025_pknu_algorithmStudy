#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define S 102

int p[S];

int find(int x) {
    if(p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    p[v] = u;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0, cnt = 0;
    for(int i=0;i<S;i++)
        p[i] = i;
    for(auto &i:costs) 
        swap(i[0], i[2]);
    sort(costs.begin(), costs.end());
    for(int i=0;i<costs.size();i++) {
        auto now = costs[i];
        if(find(now[1]) == find(now[2]))
            continue;
        merge(now[1], now[2]);
        answer += now[0];
        ++cnt;
        if(cnt == n) break;
    }
    return answer;
}