#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, m, p[500'002];

int find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

void merge(int u, int v) {
    if (u == v) return;
    p[v] = u;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        u = find(u), v = find(v);
        if (u == v) {
            cout << i;
            return 0;
        }
        merge(u, v);
    }
    cout << 0;
    return 0;
}
