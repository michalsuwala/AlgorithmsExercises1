#include  <iostream>
#include <vector>
#include <limits>
#include <queue>

void dijkstra(const std::vector<std::vector<std::pair<int, int>>>& graph, const std::vector<int>& entryTime, int start, const std::vector<int>& targets) {
    int V = graph.size();
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int u_dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(u_dist > dist[u]) continue;

        for(auto& [v, weight] : graph[u]) {
            int newDist = dist[u] + weight + entryTime[v];
            if(newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }

    for(int target : targets) {
        if(dist[target] == std::numeric_limits<int>::max()) std::cout << "NIE" << '\n';
        else std::cout << dist[target] << '\n';
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int V, E;
    std::cin >> V >> E;
    std::vector<std::vector<std::pair<int, int>>> graph(V);

    for(int i = 0; i < E; i++) {
        int a, b, d;
        std::cin >> a >> b >> d;
        graph[a].push_back({b, d});
    }

    std::vector<int> entryTime(V);
    for(int i = 0; i < V; i++) {
        std::cin >> entryTime[i];
    }

    int n;
    std::cin >> n;
    std::vector<int> targets(n);
    for (int i = 0; i < n; i++) {
        std::cin >> targets[i];
    }

    int s;
    std::cin >> s;

    dijkstra(graph, entryTime, s, targets);


    return 0;
}