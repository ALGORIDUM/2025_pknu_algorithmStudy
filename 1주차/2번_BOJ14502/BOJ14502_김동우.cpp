#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// flydongwoo : " �ʹ� ������� ... "

int N, M;
// ������ ����
vector<vector<int>> lab;
// ����� ��ġ
vector<pair<int, int>> emptySpace;
// ���̷��� ��ġ
vector<pair<int, int>> virus;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// ���̷��� �۶߸���
int spread(vector<vector<int>> copied) {
	queue<pair<int, int>> q;

	// �ʱ� ��ġ�� ť�� ������
	for (auto v : virus) {
		q.push(v);
	}

	// ���̷����� �۶߸�
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			// ������ �������� ��ĭ�̸� ���̷��� ������
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && copied[nx][ny] == 0) {
				copied[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	// ������ �� �����
	int safe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (copied[i][j] == 0) {
				safe++;
			}
		}
	}

	return safe;
}

int main() {
	cin >> N >> M;
	lab.resize(N, vector<int>(M));

	// ������ ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> lab[i][j];
			if (lab[i][j] == 0) emptySpace.push_back({ i, j }); 
			if (lab[i][j] == 2) virus.push_back({ i, j });
		}
	}

	int maxSafe = 0;

	// �� ĭ�� ����
	int numEmpty = emptySpace.size();
	vector<int> comb(numEmpty, 0);

	// ���� ����� ��ġ�� ������
	for (int i = 0; i < 3; i++) {
		comb[i] = 1;
	}
	
	sort(comb.begin(), comb.end());

	// ������ �� ����� ������ Ž����
	do {
		vector<vector<int>> copied = lab;

		for (int i = 0; i < numEmpty; i++) {
			if (comb[i] == 1) {
				int x = emptySpace[i].first;
				int y = emptySpace[i].second;
				copied[x][y] = 1;
			}
		}

		int safe = spread(copied);
		maxSafe = max(maxSafe, safe);

	} while (next_permutation(comb.begin(), comb.end()));

	cout << maxSafe << endl;

	return 0;
}