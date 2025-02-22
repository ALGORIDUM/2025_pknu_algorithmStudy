#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ���Ѵ�
const int INF = 1e9;

int V, E, K;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start }); 
    dist[start] = 0;

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // ���� ����� �Ÿ��� ���� �Ÿ����� ũ�ٸ� ����
        if (cur_dist > dist[cur_node]) continue;

        for (auto edge : graph[cur_node]) {
            int next_node = edge.first;
            int weight = edge.second;
            int new_dist = cur_dist + weight;

            if (new_dist < dist[next_node]) {
                dist[next_node] = new_dist;
                pq.push({ new_dist, next_node });
            }
        }
    }
}

int main() {
    cin >> V >> E;
    cin >> K;

    graph.resize(V + 1);
    dist.resize(V + 1, INF);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
    }

    dijkstra(K);

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }

    return 0;
}