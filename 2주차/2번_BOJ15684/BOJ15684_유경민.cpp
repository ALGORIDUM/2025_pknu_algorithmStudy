#include <iostream>
#include <vector>

using namespace std;

int N,M,H;
vector<vector<int>> sadari;

bool checking(){
    //sadari[i][j] == 1 : i번 가로행 위치에서 세로 열 j, j+1이 연결됨.
    for(int i = 1; i<=N; i++){
        int location = i; //현재 세로선 번호
        for(int j = 1; j<=H; j++){
            if(sadari[j][location] == 1) location++;
            else if(location > 1 && sadari[j][location - 1] == 1) location --;

        }
        if(location != i) return false;
    }

    return true;
}

void backtracking(int count, int x, int y){



}


int main(){

    cin >> N >> M >> H;
    sadari.assign(H+1, vector<int>(N+1,0));

    

    


    return 0;
}