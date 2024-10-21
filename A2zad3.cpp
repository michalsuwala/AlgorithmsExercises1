#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj;

    bool black = true;
    int temp;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(black) {
                std::cin >> temp;
                if(temp == 0) {
                    adj[i * n + j].push_back(-1);
                }
                else if(temp == 1) {
                    if(i > 0 && j > 1 && (adj[i * n - n + j - 2].empty() || adj[i * n - n + j - 2][0] != -1)) {
                        adj[i * n - n + j - 2].push_back(i * n + j);
                    }
                    if(j > 2 && (adj[i * n + j - 3].empty() || adj[i * n + j - 3][0] != -1)) {
                        adj[i * n + j - 3].push_back(i * n + j);
                    } 
                    if(i < n && j > 1 && (adj[i * n + n + j - 2].empty() || adj[i * n + n + j - 2][0] != -1)) {
                        adj[i * n + n + j - 2].push_back(i * n + j);
                    }                 
                }
                else if(temp == 2) {
                    if(i > 0 && (adj[i * n - n + j].empty() || adj[i * n - n + j][0] != -1)) {
                        adj[i * n - i + j].push_back(i * n + j);
                    }
                    if(j > 0 && (adj[i * n + j - 1].empty() || adj[i * n + j - 1][0] != -1)) {
                        adj[i * n + j - 1].push_back(i * n + j);
                    } 
                    if(i < n && j > 0 && (adj[i * n + i + j].empty() || adj[i * n + i + j][0] != -1)) {
                        adj[i * n + i + j].push_back(i * n + j);
                    }
                }
                else if(temp == 3) {
                    if(i > 0 && j > 1 && (adj[i * n - n + j - 2].empty() || adj[i * n - n + j - 2][0] != -1)) {
                        adj[i * n - n + j - 2].push_back(i * n + j);
                    }
                    if(j > 0 && (adj[i * n + j - 1].empty() || adj[i * n + j - 1][0] != -1)) {
                        adj[i * n + j - 1].push_back(i * n + j);
                    } 
                    if(i < n && j > 1 && (adj[i * n + n + j - 2].empty() || adj[i * n + n + j - 2][0] != -1)) {
                        adj[i * n + n + j - 2].push_back(i * n + j);
                    }  
                }
            }
        }
    }

    return 0;
}