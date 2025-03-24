// A->B 
#include<bits/stdc++.h>
using namespace std;

// int, long long 둘 다 상관 x 
int a, b, cnt=1;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    while(b>a){
        if(b%10 == 1){
            b-=1;
            b/=10;
        }
        else if(b%2 == 0){
            b/=2;
        }
        // 못 나누는 경우도 있다 
        else break;
        cnt++;
    }
    if(b==a) cout<< cnt;
    else cout<<-1;
}