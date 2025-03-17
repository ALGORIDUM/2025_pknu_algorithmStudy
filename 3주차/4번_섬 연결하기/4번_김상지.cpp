// 40m 
#include <bits/stdc++.h>

using namespace std;

vector<tuple<int,int,int>> v;
int parents[505];

int find(int t){
    if(parents[t]<0) return t;
    return parents[t] = find(parents[t]);
}

bool uni(int a, int b){
    int fir = find(a);
    int sec = find(b);
    // 연결x
    if(fir == sec) return 0;
    // 연결o
    parents[sec] = fir;
    return 1;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 0; i< costs.size(); i++){
        int a = costs[i][0];
        int b = costs[i][1];
        int c = costs[i][2];
        v.push_back({c,a,b});
        v.push_back({c,b,a});
    }
    sort(v.begin(), v.end());
    fill(parents, parents+n+1, -1);
    for(auto c : v){
        int k,m,n;
        tie(k, m, n) = c;
        if(uni(m,n)){
            answer+=k;
        }
    }
    
    return answer;
}