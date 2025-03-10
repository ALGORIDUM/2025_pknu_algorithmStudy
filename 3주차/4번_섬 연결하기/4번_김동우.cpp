#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);  
    }

    bool unionSet(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) {
            return false;
        }

        if (rank[rootA] > rank[rootB]) {
            swap(rootA, rootB);
        }
        parent[rootA] = rootB;

        if (rank[rootA] == rank[rootB]) {
            rank[rootB]++;
        }
        return true;
    }
};

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    // 비용 기준 정렬
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
        });

    UnionFind uf(n);
    int edgeCount = 0;

    // 크루스칼 알고리즘 
    for (auto& cost : costs) {
        int u = cost[0], v = cost[1], weight = cost[2];

        if (uf.unionSet(u, v)) {
            answer += weight;
            edgeCount++;
            if (edgeCount == n - 1) {
                break;
            }
        }
    }

    if (edgeCount != n - 1) {
        return -1;
    }

    return answer;
}

int main() {
    int n, m;
    cin >> n >> m;  

    vector<vector<int>> sol;
    sol.reserve(m); 

    for (int i = 0; i < m; i++) { 
        int u, v, cost;
        cin >> u >> v >> cost;
        sol.push_back({ u, v, cost });
    }

    int result = solution(n, sol);

    if (result == -1) {
        cout << "모든 섬을 연결할 수 없습니다." << endl;
    }
    else {
        cout << "최소 비용 : " << result << endl;
    }

    return 0;
}
