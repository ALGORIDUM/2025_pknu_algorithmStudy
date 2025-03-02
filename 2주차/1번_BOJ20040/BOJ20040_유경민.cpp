
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph;

int find(int x){ //부모 노드 찾기
    if(graph[x] == x) return x;
    return graph[x] = find(graph[x]);
}

void unions(int a, int b){
    //각 최상위 루트 노드 찾기
    a = find(a);
    b = find(b); 
    if(a !=b) graph[b] = a;
}

int main(){

    //N개의 점, M번의 연결
    int N,M, input_x, input_y;

    cin >> N >> M;
    graph.resize(N);

    for(int i = 0; i<N; i++){
        graph[i] = i;
    }

    for(int i = 1; i<= M; i++){//i번째에 사이클 발생하면 출력해야 해서 0이 아닌 1부터 시작작
        cin >> input_x >> input_y;

        //사이클 발생 = 이미 입력했을 당시 촤상위 루트 노드가 같으면, 
        //입력한 두 수를 연결한다는 의미에서 입력을 받으니 사이클 발생하는구나
        if(find(input_x) == find(input_y)){
            cout << i << endl;
            return 0; //메인 함수 실행 끝
        }
        //사이클 발생 x -> 합치기기
        unions(input_x, input_y);

    }
    cout << 0 << endl;

    return 0;
}


