#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define MAX 1'003
using namespace std;

int N, M, H, cur_cnt;
bool ladder[31][11];
int ans = 4;

bool chk() {
    for (int i = 1; i <= N; i++) {
        int x = i;
        for (int j = 1; j <= H; j++) {
            if (ladder[j][x]) x++;
            else if (ladder[j][x - 1]) x--;
        }
        if (x != i) return false;
    }
    return true;
}

void dfs(int count, int x, int y) {
    if (count >= ans) return;

    if (chk()) {
        ans = count;
        return;
    }
    if (count == 3) return;

    for (int i = x; i <= H; i++) {
        // j�� ���μ�
        // (1,1) > ��ٸ� |(1,2) > �����̶� x |(1,3) ��ٸ����� dfs �� ��Ʈ��ŷ |
        // (2,1) > ��ٸ����� dfs ��, ��Ʈ��ŷ |(2,2) ���� dfs �� ��Ʈ��ŷ
        for (int j = (i == x ? y : 1); j < N; j++) {
            if (!ladder[i][j] && !ladder[i][j - 1] && !ladder[i][j + 1]) {
                ladder[i][j] = true;
                dfs(count + 1, i, j + 2);
                ladder[i][j] = false;
            }
        }
    }
}

int main() {
    fastio;
    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ladder[a][b] = 1;
    }

    dfs(0, 1, 1);
    cout << (ans > 3 ? -1 : ans) << "\n";
    return 0;
}