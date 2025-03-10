#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 505

int n, m, a[S][S], v[S][S], res;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void DFS(int x, int y, int cnt, int ans) {
    if (cnt >= 4) {
        res = max(res, ans);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny]) continue;
        v[nx][ny] = 1;
        DFS(nx, ny, cnt + 1, ans + a[nx][ny]);
        if (cnt == 2) DFS(x, y, cnt + 1, ans + a[nx][ny]);
        v[nx][ny] = 0;
    }
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            v[i][j] = 1;
            DFS(i, j, 1, a[i][j]);
            v[i][j] = 0;
        }
    cout << res;
    return 0;
}
