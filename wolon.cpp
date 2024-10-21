#include <iostream>
#include <vector>

bool findVolunters(std::vector<std::pair<int, int>> &v, bool visited[], int i, int r) {
    bool res0 = false, res1 = false, res2 = false;
    
    if (i == v.size()) {
        return true;
    }

    if (!visited[v[i].first] && !visited[v[i].second]) {

        if (!visited[v[i].first] && r > 0) {
            visited[v[i].first] = true;
            res1 = findVolunters(v, visited, i + 1, r - 1);
            visited[v[i].first] = false;
        } 
        if (res1) return true;

        if (!visited[v[i].second] && r > 0) {
            visited[v[i].second] = true;
            res2 = findVolunters(v, visited, i + 1, r - 1);
            visited[v[i].second] = false;
        }
        if (res2) return true;
    }

    if (visited[v[i].first] || visited[v[i].second]) {
        res0 = findVolunters(v, visited, i + 1, r);
    }
    if (res0) return true;

    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, m, r;
        std::cin >> n >> m >> r;
        
        std::vector<std::pair<int, int>> connections;
        int a, b;
        for (int j = 0; j < m; ++j) {
            std::cin >> a >> b;
            connections.push_back({a - 1, b - 1});
        }

        bool visited[n] {false};

        bool res = findVolunters(connections, visited, 0, r);
        if (res) std::cout << "TAK" << '\n';
        else std::cout << "NIE" << '\n';

        
    }

    return 0;
}