#include <iostream>
#include <vector>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define MAX 100'003

int road[MAX], price[MAX];
int n, m, ans = 0;

//int������ �� ��, sum�� ������ �ִ� 1,000,000,000,000,000,000 �̹Ƿ� int������ �Ұ�. long long Ÿ�� ����ؾ���
long long solve(int n) {
    long long minPrice = 1e9;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (price[i] < minPrice) minPrice = price[i];
        sum += minPrice * road[i];
    }
    return sum;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
        cin >> road[i];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    cout << solve(n);

    return 0;
}