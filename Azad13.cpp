#include <iostream>
#include <string>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long m;
    int n;
    std::string arr[1500];

    std::cin >> n >> m;

    for(int i = 0; i < m; i++) {
        std::cin >> arr[i];
    }
    

    long a, b, c, d;
    int last;
    last = m - 1;
    for(int i = m; i < n; i++) {
        std::cin >> a >> b >> c >> d;
        arr[i % 1500] = "";
        arr[i % 1500] += arr[a % 1500].substr(0, 3); 
        arr[i % 1500] += arr[b % 1500].substr(3, 3); 
        arr[i % 1500] += arr[c % 1500].substr(6, 3);
        arr[i % 1500] += arr[d % 1500].substr(9, 3);
        last = i % 1500; 
    }

    std::cout << arr[last];

    return 0;
}