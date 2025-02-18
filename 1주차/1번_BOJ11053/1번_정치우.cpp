#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define S 1002

int n, arr[S], dp[S], res;

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        int cur = 0;
        for (int j = 1; j < i; j++)
            if (arr[i] > arr[j] && dp[j] > cur)
                cur = dp[j];
        dp[i] = cur + 1;
        if (dp[i] > res) res = dp[i];
    }
    cout << res;
    return 0;
}
