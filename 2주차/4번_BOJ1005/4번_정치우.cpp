#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 1002

int t, n, k, w, cost[S], ind[S], ans[S];
vector<int> adj[S];

int main() {
    fastio;
    cin >> t;
    while (t--) {
        fill(cost, cost + S, 0), fill(ind, ind + S, 0), fill(ans, ans + S, 0);
        for (int i = 0; i < S; i++) adj[i].clear();
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> cost[i];
        for (int i = 0, x, y; i < k; i++) {
            cin >> x >> y;
            adj[x].push_back(y), ++ind[y];
        }
        cin >> w;
        queue<int> q;
        for (int i = 1; i <= n; i++) if (!ind[i]) q.push(i), ans[i] = cost[i];
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int nxt: adj[now]) {
                --ind[nxt];
                if (!ind[nxt]) q.push(nxt);
                ans[nxt] = max(ans[nxt], ans[now] + cost[nxt]);
            }
        }
        cout << ans[w] << '\n';
    }
    return 0;
}
