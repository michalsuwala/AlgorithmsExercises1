#include <iostream>
#include <vector>

struct Edge {
    int to;
    int time;
    Edge(int to, int time) : to(to), time(time) {}
}; 

int main() {
    int t;
    for(int i = 0; i < t; i++) {
        int n, m, s;
        int s1, s2, time;
        std::cin >> n >> m >> s;
        std::vector<std::vector<Edge*>> graph;
        std::vector<std::vector<int>> busy;
        for(int j = 0; j < m; j++) {
            std::cin >> s1 >> s2 >> time;
            Edge *e1 = new Edge(s2, time);
            Edge *e2 = new Edge(s1, time);
            graph[s1].push_back(e1);
            graph[s2].push_back(e2);
        }
        for(int j = 0; j < n; j++) {
            int k;
            int temp;
            std::cin >> k;
            for(int l = 0; l < k; l++) {
                std::cin >> temp;
                busy[j].push_back(temp);
            }
        }
    }
} 