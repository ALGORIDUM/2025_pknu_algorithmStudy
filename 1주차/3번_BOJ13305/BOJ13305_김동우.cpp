#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	// ���� ����
	vector<long long> road(N - 1);
	// �������� �⸧ ���� ������
	vector<long long> price(N);

	for (int i = 0; i < N - 1; i++) {
		cin >> road[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}

	long long totalCost = 0;
	long long minPrice = price[0];

	// ��� ���� ��ȸ
	for (int i = 0; i < N - 1; i++) {
		if (price[i] < minPrice) {
			// �ּ� �⸧
			minPrice = price[i];
		}
		totalCost += minPrice * road[i];
	}

	cout << totalCost << endl;

	return 0;
}