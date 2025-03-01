#include<bits/stdc++.h>
using namespace std;

int n, m;
int total = 0;
vector<int> v(1000005, -1);
bool check = false;

int fin(int c){
    if(v[c]<0) return c;
    return v[c] = fin(v[c]);
}

bool uni(int a, int b, int num){
    int fir = fin(a);
    int sec = fin(b);
    if(fir == sec){
        cout<<num+1;
        return 1;
    }
    v[sec] = fir;
    return 0;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >>a >> b;
        if(uni(a, b, i)) return 0;

    }
    cout<< 0;
}