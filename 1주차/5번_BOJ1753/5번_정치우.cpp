#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define pii pair<int,int>
#define SIZE 20'002

int v, e, s, d[SIZE];
vector<pii > adj[SIZE]; // pair<cost, nxt>
priority_queue<pii, vector<pii >, greater<> > pq; // pair<cost, nxt>

int main() {
    fastio;
    cin >> v >> e >> s;
    while (e--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    fill(&d[0], &d[SIZE], 1e9);
    d[s] = 0, pq.push({d[s], s});
    while (!pq.empty()) {
        auto now = pq.top();
        pq.pop();
        if (d[now.second] != now.first) continue;
        for (auto nxt: adj[now.second]) {
            if (d[nxt.second] <= d[now.second] + nxt.first) continue;
            d[nxt.second] = d[now.second] + nxt.first;
            pq.push({d[nxt.second], nxt.second});
        }
    }
    for (int i = 1; i <= v; i++) {
        if (d[i] == 1e9) cout << "INF\n";
        else cout << d[i] << '\n';
    }
    return 0;
}
