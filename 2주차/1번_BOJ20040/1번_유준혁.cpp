#include <iostream>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define MAX 500'003
using namespace std;

int parent[MAX];
int n, m, k, a, b;

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (u >= v)
            parent[u] = v;
        else
            parent[v] = u;
    }
}

bool Same(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return true;
    return false;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (Same(a, b)) {
            cout << i + 1;
            return 0;
        }
        merge(a, b);
    }
    cout << 0;
    return 0;
}
