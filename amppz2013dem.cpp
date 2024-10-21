#include <bits/stdc++.h>

class Compare {
public:
    bool operator()(std::vector<int> a, std::vector<int> b) {
        if (a[0] > b[0]) return true;
        return false;
    }
};

int main () {
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Compare> pq;
    std::unordered_set<int> current;  //index
    std::map<std::string, int> mp;

    int n;
    std::cin >> n;

    int a, b;
    for (int i = 0; i < n; ++i) {
        std::cin >> a >> b;
        pq.push({a, 0, i});         //start time, start, index
        pq.push({b, 1, i});
    }

    int layers = 0;
    int last = 0;
    while (!pq.empty()) {
        if (pq.top()[1]) {
            ++layers;
            if (layers == 1) {
                last = pq.top()[0];
            }
            else if (layers == 2) {
                std::string key = "";
                for (auto cur : current) {
                    key += cur + " ";
                }
                if (mp.find(key) != mp.end()) {
                    mp[key] += pq.top()[0] - last;
                }
                else mp[key] = pq.top()[0] - last;
                last = pq.top()[0];
            }
            current.insert(pq.top()[2]);
        }
        else if (!pq.top()[1]) {
            --layers;
            if (layers == 0 || layers == 1) {
                std::string key = "";
                for (auto& cur : current) {
                    key += cur + " ";
                    if (mp.find(key) != mp.end()) {
                        mp[key] += pq.top()[0] - last;
                    }
                    else mp[key] = pq.top()[0] - last;
                    last = pq.top()[0];
                }
            }
            else if (layers == 1) {
                std::string key = "";
                for (auto& cur : current) {
                    key += cur + " ";
                }
                if (mp.find(key) != mp.end()) {
                    mp[key] += pq.top()[0] - last;
                }
                else mp[key] = pq.top()[0] - last;
                last = pq.top()[0];
            }
            last = pq.top()[0];
            current.erase(pq.top()[2]);
        }
        pq.pop();
    }

    for (const auto& pair : mp) {
        std::cout << "\"" << pair.first << "\" : " << pair.second << "\n";
    }



    return 0;
}