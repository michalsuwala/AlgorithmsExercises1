#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

std::pair<std::vector<std::string>, std::vector<long>> quicksort(std::pair<std::vector<std::string>, std::vector<long>> p) {
        std::vector<std::string> names = p.first;
        std::vector<long> results = p.second;
        if(results.size() < 2) return p;
        else {

            int x = results[rand() / (RAND_MAX / results.size())];

            std::vector<std::string> n1, n2, n3;
            std::vector<long> r1, r2, r3;

            std::pair<std::vector<std::string>, std::vector<long>> p1(n1, r1);
            std::pair<std::vector<std::string>, std::vector<long>> p2(n2, r2);
            std::pair<std::vector<std::string>, std::vector<long>> p3(n3, r3);
            
            for(int i = 0; i < results.size(); i++) {
                if(results[i] < x) {
                    r1.push_back(results[i]);
                    n1.push_back(names[i]);
                }
                else if(results[i] > x) {
                    r2.push_back(results[i]);
                    n2.push_back(names[i]);
                }
                else {
                    r3.push_back(results[i]);
                    n3.push_back(names[i]);
                }
            }

            p1 = quicksort(p1);
            p2 = quicksort(p2);

            r1.insert(r1.end(), r3.begin(), r3.end());
            r1.insert(r1.end(), r2.begin(), r2.end());

            n1.insert(n1.end(), n3.begin(), n3.end());
            n1.insert(n1.end(), n2.begin(), n2.end());
            
            std::pair<std::vector<std::string>, std::vector<long>> rPair(n1, r1);
            return rPair;
        }
    }

int main() {
    std::srand(std::time(NULL));
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    long n;
    std::cin >> n;

    std::string name;
    double p;
    int d;
    long res;

    std::vector<std::string> names;
    std::vector<long> results;

    for(int i = 0; i < n; i++) {
        std::cin >> std::ws;
        std::getline(std::cin, name);
        std::cin >> p >> d;
        res = long(p * 1000 / (0.0254 * d * 3.141593));
        names.push_back(name);
        results.push_back(res);
    }

    std::pair<std::vector<std::string>, std::vector<long>> rPair(names, results);
    rPair = quicksort(rPair);
    names = rPair.first;
    results = rPair.second;

    for(int i = 0; i < 3; i++) {
        std::cout << names[i] << '\n' << results[i] << '\n';
    }

    return 0;
}