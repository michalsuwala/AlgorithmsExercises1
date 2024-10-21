#include <iostream>
#include <vector>
#include <queue>



struct Juice {
    std::string name;
    int index;

    Juice(std::string n) : name(n) {}

    Juice(std::string n, int i) : name(n), index(i) {}
};

auto comp=[](const Juice& j1,const Juice& j2)
        { 
            return j1.index < j2.index;
        };

std::priority_queue<Juice, std::vector<Juice>, decltype(comp)> pq(comp);
std::vector<std::string> juices;


void bfs(std::vector<std::vector<Juice>> graph, Juice juice) {
    if (graph[juice.index].empty()) {
        std::cout <<'z';
        pq.push(juice);
    }
    else {
        for (Juice j : graph[juice.index]) {
            bfs(graph, j);
            if (!graph[j.index].empty()) {
                    graph[j.index].erase(graph[j.index].begin());
                }
        }
    }
    std::cout<<'d';
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> res;
    std::string juice;
    for (int i = 0; i < n; ++i) {
        std::cin >> juice;
        juices.push_back(juice);
    }

    std::vector<std::vector<Juice>> graph(n);

    std::string juice2;
    for (int i = 0; i < m; ++i) {
        std::cin >> juice >> juice2;
        Juice j1(juice);
        Juice j2(juice2);
        for (int i = 0; i < n; ++i) {
            if(juices[i] == juice) {
                j1.index = i;
            }
            else if(juices[i] == juice2) {
                j2.index = i;
            }
        }
        graph[j1.index].push_back(j2);
    }

    std::cout << 'a';
   
   bool f = true;
    while(!pq.empty() || f) {
        f = false;
        std::cout << 'b';
        while(!pq.empty()) {
            res.push_back(pq.top().name);
            pq.pop();
        }
        for (int i = 0; i < m; ++i) {
            std::cout << 'c';
            if (graph[i].empty()) {
                pq.push(Juice(juices[i], i));
            }
            else {
                bfs(graph, graph[i][0]);
                if (graph[graph[i][0].index].empty() && !graph[i].empty()) {
                    graph[i].erase(graph[i].begin());
                }
            }
        }

    }


    for (std::string s : res) {
        std::cout << s << ' ';
    }
    return 0;
}