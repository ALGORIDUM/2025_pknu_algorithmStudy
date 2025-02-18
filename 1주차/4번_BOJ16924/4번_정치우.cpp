#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, m, sz;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
char s[102][102], v[102][102];
vector<tuple<int, int, int> > res;

void f(int x, int y) {
    for (int k = 1; k <= sz / 2; k++) {
        for (int i = 0; i < 4; i++) {
            int nx = x + (dx[i] * k), ny = y + (dy[i] * k);
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || s[nx][ny] != '*') return;
        }
        v[x][y] = '*';
        for (int i = 0; i < 4; i++) {
            int nx = x + (dx[i] * k), ny = y + (dy[i] * k);
            v[nx][ny] = '*';
        }
        res.push_back({x + 1, y + 1, k});
    }
}

int main() {
    fastio;
    cin >> n >> m;
    sz = min(n, m);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '*')
                f(i, j);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == '*' && v[i][j] != '*') {
                cout << -1;
                return 0;
            }
    cout << res.size() << '\n';
    for (auto [x,y,z]: res)
        cout << x << ' ' << y << ' ' << z << '\n';
    return 0;
}
