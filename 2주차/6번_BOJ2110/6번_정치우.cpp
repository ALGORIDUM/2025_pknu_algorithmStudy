#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, c, a[200'002], res;

int F(int l) {
    int ans = 1, cur = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] - cur >= l)
            ++ans, cur = a[i];
    if (ans >= c) return 1;
    return 0;
}

int main() {
    fastio;
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int s = 1, e = 1e9;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (F(mid)) {
            res = max(res, mid);
            s = mid + 1;
        } else e = mid - 1;
    }
    cout << res;
    return 0;
}
