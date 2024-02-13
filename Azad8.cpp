#include <iostream>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, s, d;
    std::cin >> n >> m >> s >> d;
    std::vector<std::vector<int>> adjList(n);
    int level[n];
    bool check[n];
    for(int i = 0; i < n; i++) {
        check[i] = true;
    }
    

    int a, b;
    for(int i = 0; i < m; i++) {
        std::cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int count = 0;
    std::queue<int> q;
    q.push(s);
    level[s] = 0;
    check[s] = false;

    int maxLvl = 0;
    int current;
    while(!q.empty()) {
        current = q.front();
        
        q.pop();

        for(int ind : adjList[current]) {           
            if(check[ind]) {
                q.push(ind);
                check[ind] = false;
                maxLvl = level[current] + 1;
                level[ind] = maxLvl; 
                if(maxLvl * 2 <= d) count++;
            }
        }
    }

    std::cout << maxLvl << " " << count;

    return 0;
}