#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
#define S 100'002

int n;
ll d[S], MIN = INT_MAX, res;

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i < n; i++) cin >> d[i];
    for (int i = 1, p; i < n; i++) {
        cin >> p;
        if (MIN > p) MIN = p;
        res += MIN * d[i];
    }
    cout << res;
    return 0;
}
