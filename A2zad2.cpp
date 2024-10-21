#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    double res = 1.0;
    bool visited[n] {0};
    std::vector<std::vector<std::pair<int, double>>> adj(n); 

    int a, b;
    double c;
    for(int i = 0; i < m; ++i) {
        std::cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    std::priority_queue<std::pair<int, double>, std::vector<std::pair<int, double>>> pq;

    pq.push({0, 1.0});

    int idx;
    double prob;
    for(int i = 0; !pq.empty(); ++i) {
        std::cout << pq.top().first << " " << pq.top().second << '\n';
        idx = pq.top().first;
        prob = pq.top().second;
        pq.pop();
        if(visited[idx]) continue;

        visited[idx] = true;
        res *= prob;
        for(auto r : adj[idx]) {
            if(!visited[r.first]) pq.push(r);
        }
    }

    std::cout << std::fixed << std::setprecision(5) << res;

    return 0;
}


