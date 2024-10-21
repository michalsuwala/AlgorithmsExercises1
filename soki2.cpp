#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>


void topologicalSort(std::unordered_map<std::string, std::vector<std::string>> graph, std::unordered_map<std::string, int> indegree) {
    std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> pq;

    for (auto i : indegree) {
        if (i.second == 0) {
            pq.push(i.first);
        }
    }

    while (!pq.empty()) {
        std::string current = pq.top();
        pq.pop();
        std::cout << current << '\n';

        for (std::string neighbor : graph[current]) {
            --indegree[neighbor];
            if (indegree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::unordered_map<std::string, std::vector<std::string>> graph;
    std::unordered_map<std::string, int> indegree;

    std::string juice;
    for (int i = 0; i < n; ++i) {
        std::cin >> juice;
        graph[juice] = std::vector<std::string>();
        indegree[juice] = 0;
    }

    std::string juice1, juice2;
    for (int i = 0; i < m; ++i) {
        std::cin >> juice1 >> juice2;
        graph[juice1].push_back(juice2);
        ++indegree[juice2];
    }

    topologicalSort(graph, indegree);

    return 0;
}
