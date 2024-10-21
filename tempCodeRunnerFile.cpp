#include <iostream>
#include <vector>

bool findVolunters(std::vector<std::pair<int, int>> v, std::vector<bool> visited, int i, int r) {
    bool res0, res1, res2;
    if (i == v.size()) {
        return true;
    }
    if (visited[v[i].first] && visited[v[i].second] || r < 0) {
        return false;
    }
    else {
        if (visited[v[i].first] || visited[v[i].second]) {
            res0 = findVolunters(v, visited, i + 1, r);
        }
        if(res0) return true;
        if (!visited[v[i].first]) {
            visited[v[i].first] = true;
            res1 = findVolunters(v, visited, i + 1, r - 1);
            visited[v[i].first] = false;
        }
        if (res1) return true;
        if (!visited[v[i].second]) {
            visited[v[i].second] = true;
            res2 = findVolunters(v, visited, i + 1, r - 1);
            visited[v[i].second] = false;
        }
        return res0 || res1 || res2;
    }
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

        std::vector<bool> visited(n, false);

        bool res = findVolunters(connections, visited, 0, r);
        if (res) std::cout << "TAK" << '\n';
        else std::cout << "NIE" << '\n';

        
    }

    return 0;
}