#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;

    int residents[n + 1] {0};
    std::vector<std::vector<int>> graphs;
    char c;
    int temp1, temp2;

    graphs.resize(n + 1);
    for(int i = 0; i < q; ++i) {
        std::cin >> c;
        if(c == '?') {
            std::cin >> temp1;
            if(residents[temp1] == 0) std::cout << "0";
            else if(residents[temp1] > 0) std::cout << "?";
            else std::cout << "1";
        }
        else if(c == '-') {
            std::cin >> temp1;
            auto it = std::find(graphs[residents[temp1] - 1].begin(), graphs[residents[temp1] - 1].end(), temp1);
            if(it != graphs[residents[temp1] - 1].end()) {
                graphs[residents[temp1] - 1].erase(it);
            }
            residents[temp1] = 0;
        }
        else {
            std::cin >> temp1 >> temp2;
            if(residents[temp1] == -1) {
                residents[temp2] = -1;
            }
            else if(temp1 == temp2) {
                if(residents[temp1] > 0) {
                    for(int i : graphs[residents[temp1] - 1]) {
                    residents[i] = -1;
                }
                }
                residents[temp1] = -1;
            }
            else if(residents[temp2] == -1) {
                residents[temp1] = -1;
            }
            else if(residents[temp1] == residents[temp2] && residents[temp1] == 0) {
                residents[temp1] = graphs.size() + 1;
                residents[temp2] = graphs.size() + 1;
                graphs.push_back({temp1, temp2});
            }
            else if(residents[temp1] > 0 && residents[temp2] == 0){
                residents[temp2] = residents[temp1];
                graphs[residents[temp1] - 1].push_back(temp2);
            }
            else if(residents[temp2] > 0 && residents[temp1] == 0){
                residents[temp1] = residents[temp2];
                graphs[residents[temp2] - 1].push_back(temp1);
            }
            else if(residents[temp1] > 0 && residents[temp2] > 0 && residents[temp1] != residents[temp2]) {
                for(int i : graphs[residents[temp2] - 1]) {
                    graphs[residents[temp1] - 1].push_back(i);
                    residents[i] = residents[temp1];
                }
            }
            else if(residents[temp1] > 0 && residents[temp2] > 0 && residents[temp1] == residents[temp2]) {
                for(int i : graphs[residents[temp2] - 1]) {
                    residents[i] = -1;
                }
            }
        }
    }
    return 0;
}