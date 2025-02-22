#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> B(N, 1);

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		A[i] = p;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				B[i] = max(B[i], B[j] + 1);
			}
		}
	}

	int maxLen = *max_element(B.begin(), B.end());

	cout << maxLen << endl;

	return 0;
}