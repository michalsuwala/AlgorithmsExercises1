#include <bits/stdc++.h>

int main () {
    std::priority_queue<std::pair<int, int>> friends;
    std::priority_queue<int> buckles;
    int res = 0;

    int n, k;
    std::cin >> n >> k;

    int d, l;
    for (int i = 0; i < n; ++i) {
        std::cin >> d;
        friends.push({d, 1});
    }

    for (int i = 0; i < k; ++i) {
        std::cin >> l;
        buckles.push(l);
    }

    while (!friends.empty() && !buckles.empty()) {
        if (friends.top().second) {
            if (5 * friends.top().first <= buckles.top()) {
                ++res;
                friends.pop();
                buckles.pop();
            }
            else if (3 * friends.top().first <= buckles.top()) {
                ++res;
                friends.push({friends.top().first, 0});
                friends.pop();
                buckles.pop();
            }
            else break;
        }
        else {
            if (2 * friends.top().first <= buckles.top()) {
                ++res;
                friends.pop();
                buckles.pop();
            }
            else break;
        }
    }

    if (!friends.empty()) std::cout << "NIE";
    else std::cout << res;

    return 0;
}