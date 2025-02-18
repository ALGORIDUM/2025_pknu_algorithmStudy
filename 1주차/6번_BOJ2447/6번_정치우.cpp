#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n;

void f(int x, int y, int s) {
    if ((x / s) % 3 == 1 && (y / s) % 3 == 1) cout << ' ';
    else {
        if (s / 3) f(x, y, s / 3);
        else cout << '*';
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            f(i, j, n);
        cout << '\n';
    }
    return 0;
}
