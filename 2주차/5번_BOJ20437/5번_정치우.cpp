#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int t, k, n;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        string s;
        cin >> s >> k;
        vector<vector<int> > v(28);
        for (int i = 0; i < s.size(); i++)
            v[s[i] - 'a'].push_back(i);
        int MIN = INT_MAX, MAX = 0;
        for (auto i: v) {
            for (int s = 0, e = k - 1; e < i.size(); s++, e++) {
                MIN = min(MIN, i[e] - i[s] + 1);
                MAX = max(MAX, i[e] - i[s] + 1);
            }
        }
        if (MIN == INT_MAX) cout << "-1\n";
        else cout << MIN << ' ' << MAX << '\n';
    }
    return 0;
}
