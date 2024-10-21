#include <bits/stdc++.h>

std::vector<int> countGroupsBackward(std::vector<int> v,  int k) {
    int count = 0;
    std::vector<int> res(v.size());
    std::vector<int> counts;
    for (int i = 0; i < 1000001; ++i) {
        counts.push_back(0);
    }

    int last1 = v.size() - 1;
    for (int i = v.size() - 1; i >= 0; --i) {
        ++counts[v[i]];
        if (counts[v[i]] != k) res[i] = count;
        else {
            ++count;
            res[i] = count;
            for (int j = i; j <= last1; ++j) {
                --counts[v[j]];
            }
            last1 = i - 1;
        }
    }

    return res;
}

int firstElement(std::vector<int> v, int begin, int end, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    std::vector<int> counts;
    for (int i = 0; i < 1000001; ++i) {
        counts.push_back(0);
    }

    for (int i = begin; i <= end; ++i) {
        ++counts[v[i]];
        if (counts[v[i]] == k) {
            pq.push(v[i]);
        }
    }

    return pq.top();
}

int main() {
    std::vector<int> v;

    int n, k;
    std::cin >> n >> k;
    
    int t;
    for (int i = 0; i < n; ++i) {
        std::cin >> t;
        v.push_back(t);
    }

    std::vector<int> backward = countGroupsBackward(v, k);

    //for (int i : backward) std:: cout << i << ' ';

    std::cout << backward[0] * k << '\n';

    int count = backward[0] - 1;
    int begin = 0;
    for (int i = 1; i < backward.size() - 2; ++i) {
        if (backward[i + 2] >= count) continue;
        else {
            int temp = firstElement(v, begin, i, k);
            for (int j = 0; j < k; ++j) std::cout << temp << ' ';
            begin = i + 1;
            --count;
        }
    }

    if (begin < v.size()) {
        int temp = firstElement(v, begin, v.size() - 1, k);
        for (int j = 0; j < k; ++j) {
            std::cout << temp << ' ';
        }
    }
    
    return 0;
}