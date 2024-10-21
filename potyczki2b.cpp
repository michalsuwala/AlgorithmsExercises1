#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

int counter = 0;


std::pair<std::string, std::string> dfs(std::vector<std::vector<int>> graph, bool visited[], int start, int goal) {
    std::queue<std::tuple<int, int, std::string, std::string>> q;
    for(int i : graph[start]) {
        if(!visited[i]) {
            q.push(std::make_tuple(i, 0, "", ""));
            visited[i] = 1;
        }
    }
    while(!q.empty()) {
        auto [current, count, str,str2] = q.front();
        q.pop();
        for(int i : graph[current]) {
            if(i == goal) {
                counter += count + 1;
                return std::make_pair(str + "+ " + std::to_string(start) + " " + std::to_string(i) + "\n", str2);
            }
            if(!visited[i]) {
                q.push(std::make_tuple(i, count + 2, str + "+ " + std::to_string(start) + " " + std::to_string(i) + "\n", 
                str2 + "- " + std::to_string(i) + " " + std::to_string(start) + "\n"));
                visited[i] = 1;
            }
        }
    }
    return {"", ""};
}

int main() {
    std::string res = "";
    std::string res2 = "";
    int n;
    std::cin >> n;
    
    std::vector<std::vector<int>> graph1(n + 1);
    std::vector<std::vector<int>> graph2(n + 1);

    int m1, m2, a, b;
    std::cin >> m1;
    for(int i = 0; i < m1; ++i) {
        std::cin >> a >> b;
        graph1[a].push_back(b);
        graph1[b].push_back(a);
    }

    std::cin >> m2;
    for(int i = 0; i < m2; ++i) {
        std::cin >> a >> b;
        graph2[a].push_back(b);
        graph2[b].push_back(a);
    }
    

    for(int i = 1; i < n + 1; ++i) {
        for(int j : graph2[i]) {
            if(!(std::find(graph1[i].begin(), graph1[i].end(), j) != graph1[i].end())) {
                bool visited[n] {0};
                std::pair<std::string, std::string> temp = dfs(graph1, visited, i, j);
                res += temp.first;
                res2 += temp.second;
                graph1[i].push_back(j);
                graph1[j].push_back(i);
            }
        }
    }

    for(int i = 1; i < n + 1; ++i) {
        for(int j : graph1[i]) {
            if(!(std::find(graph2[i].begin(), graph2[i].end(), j) != graph2[i].end())) {
                res += "- " + std::to_string(i) + " " + std::to_string(j) + "\n";
                ++counter;
            }
            graph1[j].erase(std::find(graph1[j].begin(), graph1[j].end(), i));

        }
    }

    std::cout << counter << '\n' << res << res2;

    return 0;
}