/*#include <iostream>
#include <vector>
#include <limits>
#include <queue>

int main() {
    int L, M, P;
    std::cin >> L >> M >> P;

    std::vector<std::pair<int, int>> stations(P + 2);
    for(int i = 1; i < P + 1; ++i) {
        std::cin >> stations[i].first >> stations[i].second;
    }

    std::vector<int> cost(P + 2, std::numeric_limits<int>::max());
    cost[0] = 0;
    stations[0] = {0, 0};
    cost[P + 1] = std::numeric_limits<int>::max();
    stations[P + 1] = {L, 0};
    int max_idx = 0;


    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, 0});
    while(max_idx != P + 1) {
        int c_idx = pq.top().first;
        int c_cost = pq.top().second;
        int min_cost =  std::numeric_limits<int>::max();
        max_idx = c_idx;
        for(int i = c_idx; stations[i].first <= stations[c_idx].first + M && i < L; i++) {
            max_idx++;
        }
        for(int i = max_idx; i > c_idx; i--) {
            if(c_cost + stations[i].second > min_cost) continue;
            min_cost = c_cost + stations[i].second;
            if(cost[i] > c_cost + stations[i].second) {
                cost[i] = c_cost + stations[i].second;
                pq.push({i, min_cost});
            }
        }
    }

    if(cost[P + 1] == std::numeric_limits<int>::max()) {
        std::cout << -1;
    } else {
        std::cout << cost[P + 1];
    }
    return 0;
}*/

#include <iostream>
#include <vector>
#include <limits>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int L, M, P;
    std::cin >> L >> M >> P;

    std::vector<std::pair<int, int>> stations(P + 2);
    stations[0] = {0, 0}; 
    for(int i = 1; i <= P; ++i) {
        std::cin >> stations[i].first >> stations[i].second;
    }
    stations[P + 1] = {L, 0}; 

    std::vector<int> cost(P + 2, std::numeric_limits<int>::max());
    cost[0] = 0; 

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, 0}); 

    while(!pq.empty()) {
        int c_idx = pq.top().second;
        int c_cost = pq.top().first;
        pq.pop();

        if(c_idx == P + 1) break; 

        for(int i = c_idx + 1; i <= P + 1; i++) {
            if(stations[i].first - stations[c_idx].first > M) break;
            
            int new_cost = c_cost + stations[i].second;
            if(cost[i] > new_cost) {
                cost[i] = new_cost;
                pq.push({new_cost, i});
            }
        }
    }

    if(cost[P + 1] == std::numeric_limits<int>::max()) {
        std::cout << -1;
    } else {
        std::cout << cost[P + 1];
    }

    return 0;
}
