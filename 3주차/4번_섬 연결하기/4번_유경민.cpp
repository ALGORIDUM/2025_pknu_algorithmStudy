#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph;

int find(int x){
    if(graph[x] == x) return x;
    return graph[x] = find(graph[x]);
}

void unions(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) graph[b] = a;
}


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    graph.resize(n);
    for(int i = 0; i<n; i++){ //각 노드 일단 자기 자신이 부모. 
        graph[i] = i;
    }
    
    //가중치 기준 오름차순 정렬.
    sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b){
            return a[2] < b[2];   
        }
    );
    //가중치 기준으로 정렬되어 있으니까
    int cnt = 0;
    for(auto &i : costs){
        int node_1 = i[0]; 
        int node_2 = i[1];
        int cost = i[2]; // for문 통해서 i가 참조하는 거 순서대로 돌면서 각 노드 연결하는 비용 저장
        
        if(find(node_1) != find(node_2)){ //사이클 발생 안하면 합치고,
            unions(node_1, node_2);
            answer += cost;
            cnt++;
        }
        
        if(cnt == n-1) break;
        
    }
    
    return answer;
}