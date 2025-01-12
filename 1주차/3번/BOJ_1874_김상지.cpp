#include <bits/stdc++.h>
using namespace std;

stack<int> s;
string p;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int len, i = 1, t = 0;
    cin >> len;
    int a, r = 0;
    while (len--){
        cin >> a;
        t = 0;
        while (t == 0){
            if (a >= i){
                s.push(i++);
                p += "+\n";
                r++; 
            }
            else if (!s.empty() && a == s.top()){
                s.pop();
                p += "-\n";
                r++;
                t = 1;
            }
            else if (s.top() != a){
                cout << "NO";
                return 0;
            }
        }
    }
    for (auto c : p){
        cout << c;
    }
    return 0;
}