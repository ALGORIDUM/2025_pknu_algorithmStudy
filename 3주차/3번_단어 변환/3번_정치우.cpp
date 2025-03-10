#include <bits/stdc++.h>
using namespace std;
#define WORDSETSIZE 55

int res = WORDSETSIZE;
bool vis[WORDSETSIZE] = {0};

void DFS(string &begin, string &target, vector<string> &words, int cnt) {
    for(int i=0;i<words.size();i++) {
        int diff = 0;
        for(int j=0;j<words[i].size();j++)
            if(begin[j] != words[i][j] && !vis[i])
                ++diff;
        if(diff == 1) {
            if(words[i] == target) {
                res = min(res, cnt + 1);
                return;
            }
            else {
                vis[i] = 1;
                DFS(words[i], target, words, cnt + 1);
                vis[i] = 0;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    DFS(begin, target, words, 0);
    return (res == WORDSETSIZE) ? 0 : res;
}