#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, m, h, board[32][12], res = 1e9;

int C() {
    for (int i = 1; i <= n; i++) {
        int now = i;
        for (int j = 1; j <= h; j++) {
            if (board[j][now]) ++now;
            else if (now > 1 && board[j][now - 1]) --now;
        }
        if (i != now) return 0;
    }
    return 1;
}

void F(int x, int y, int ans) {
    if (ans >= 4 || ans >= res) return;
    if (C()) {
        res = min(res, ans);
        return;
    }
    for (int i = x; i <= h; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j]) continue;
            board[i][j] = 1;
            F(i, j + 1, ans + 1);
            board[i][j] = 0;
        }
    }
}

int main() {
    fastio;
    cin >> n >> m >> h;
    while (m--) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
    }
    F(1, 1, 0);
    cout << (res == 1e9 ? -1 : res);
    return 0;
}
