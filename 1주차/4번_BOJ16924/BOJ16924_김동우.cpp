// ���� ������ ..

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<char>> grid;
vector<vector<bool>> used;
vector<vector<int>> cross;

// Ȯ�� ����?
bool expand(int x, int y, int size) {
	if (x - size < 0 || x + size >= N || y - size < 0 || y + size >= M) {
		return false;
	}
	if (grid[x - size][y] != '*' || grid[x + size][y] != '*') {
		return false;
	}
	if (grid[x][y - size] != '*' || grid[x][y + size] != '*') {
		return false;
	}
	return true;
}

// ���ڰ� ã��
void find() {
    for (int i = 0; i < N; i++) {  
        for (int j = 0; j < M; j++) {
            // ���ڰ� �߽�
            if (grid[i][j] == '*') { 
                int size = 0;
                while (expand(i, j, size + 1)) {
                    size++;  
                }
                if (size > 0) {
                    cross[i][j] = size;
                    // �߽�
                    used[i][j] = true; 
                    for (int s = 1; s <= size; s++) {
                        // ���Ʒ�
                        used[i - s][j] = used[i + s][j] = true;  
                        // �¿�
                        used[i][j - s] = used[i][j + s] = true;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    grid.resize(N, vector<char>(M));
    used.resize(N, vector<bool>(M, false));
    cross.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    find();

    vector<pair<int, int>> crosses;
    vector<int> sizes;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (used[i][j] && cross[i][j] > 0) {
                crosses.push_back({ i + 1, j + 1 });
                sizes.push_back(cross[i][j]);
            }
        }
    }

    // ���ڰ� �ϳ��� ���� ��
    if (crosses.empty()) {
        cout << -1 << endl;
    }
    else {
        cout << crosses.size() << endl;
        for (size_t i = 0; i < crosses.size(); i++) {
            cout << crosses[i].first << " " << crosses[i].second << " " << sizes[i] << endl;
        }
    }
    return 0;
}