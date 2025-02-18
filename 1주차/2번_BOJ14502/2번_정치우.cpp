#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, m, a[9][9], v[9][9], res;

int f(int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] || a[i][j] == 1) return 0;
    v[i][j] = 1;
    return f(i - 1, j) + f(i, j - 1) + f(i + 1, j) + f(i, j + 1) + 1;
}

void go(int idx, int cnt) {
    if (cnt == 3) {
        int virus = 0, wall = 0;
        fill(v[0], v[9], 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 2) virus += f(i, j);
                else if (a[i][j] == 1) ++wall;
            }
        res = max(res, n * m - wall - virus);
        return;
    }
    for (int i = idx; i < n * m; i++) {
        int r = i / m, c = i % m;
        if (a[r][c]) continue;
        a[r][c] = 1;
        go(idx + 1, cnt + 1);
        a[r][c] = 0;
    }
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    go(0, 0);
    cout << res;
    return 0;
}
