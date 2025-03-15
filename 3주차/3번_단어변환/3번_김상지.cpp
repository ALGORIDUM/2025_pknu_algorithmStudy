// 40m
#include <bits/stdc++.h>

using namespace std;

int vis[52] = {0,};

bool ischange(string cur, string tar, int leng){
    int num=0;
    for(int i=0; i<leng; i++){
        if(cur[i] == tar[i]) num++;
    }
    if(num == leng-1) return 1;
    else return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int len = words[0].size(); // 단어 길이 
    queue<pair<string, int>> q;
    q.push({begin, 0});
    while(!q.empty()){
        auto [cur, num] = q.front();
        q.pop();
        if(cur == target) return num;
        for(int i=0; i<words.size(); i++){
            // 검사 한 단어 
            if(vis[i]) continue;
            if(ischange(cur, words[i], len)){
                q.push({words[i], num+1});
                answer++;
                vis[i] = 1;
            }
        }
    }
    return 0;
}