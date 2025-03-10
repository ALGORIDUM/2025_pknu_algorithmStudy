#include <bits/stdc++.h>
using namespace std;

int columns, rows;
vector<int> candidate;

bool is_unique(vector<vector<string>> &relation, int mask) {
    set<string> st;
    for(auto row:relation) {
        string s;
        for(int i=0;i<columns;i++) 
            if(mask & (1<<i))
                s+=row[i];
        if(st.count(s)) return false;
        st.insert(s);
    }
    return true;
}

void findCandidate(vector<vector<string>> &relation) {
    for(int mask=1;mask<(1<<columns);mask++) {
        bool flag = false;
        for(int cand:candidate) 
            if((mask & cand) == cand) {
                flag = true;
                break;
            }
        if(flag) continue;
        if(is_unique(relation, mask))
            candidate.push_back(mask);
    }
}

int solution(vector<vector<string>> relation) {
    columns = relation[0].size(), rows = relation.size();
    findCandidate(relation);
    return candidate.size();
}