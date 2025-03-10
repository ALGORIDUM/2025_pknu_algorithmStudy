#include <iostream>
#include <vector>
#include <queue>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define MAX 1'003
using namespace std;

int ind[MAX], dp[MAX];
int T, N, K, w;
vector<int> node[MAX], sum(MAX, 0);
queue<int> q;

int main() {
    fastio;
    cin >> T;
    while (T--) {
        cin >> N >> K;
        int time[MAX];
        for (int i = 1; i <= N; i++) {
            node[i].clear();
        }
        while (!q.empty()) q.pop();

        for (int i = 1; i <= N; i++) {
            cin >> time[i];
        }
        while (K--) {
            int x, y;
            cin >> x >> y;
            node[x].push_back(y);
            ind[y]++;
        }
        cin >> w;
        for (int i = 1; i <= N; i++) {
            if (ind[i] == 0) {
                q.push(i);
            }
            dp[i] = time[i];
        }
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int nxt : node[cur]) {
                ind[nxt]--;
                dp[nxt] = max(dp[nxt], dp[cur] + time[nxt]);
                if (ind[nxt] == 0) q.push(nxt);
            }
        }
        cout << dp[w] << "\n";
    }
    return 0;
}
