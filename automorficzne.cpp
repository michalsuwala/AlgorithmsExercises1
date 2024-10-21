#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    int num[n];
    char c;
    for(int i = 0; i < n; ++i) {
        std::cin >> c;
        num[i] = c - '0';
    }
    int res[n] {0};



    bool f = true;

    for(int i = n - 1; i >= 0; --i) {
        int j = i;
        for(int k = n - 1; k >= j + (k - j) / 2; --k) {
            if(j != k) {
                res[i] += num[k] * num[j] * 2;
                if(res[i] > 99) {
                    if(i > 1) {
                        res[i - 2] += res[i] / 100;
                    }
                    res[i] = res[i] % 100;
                    if(res[i - 2] > 9) {
                        if(i > 2) {
                            res[i - 3] += res[i - 2] / 10;
                        }
                        res[i - 2] = res[i - 2] % 10;
                    }
                } 
            }
            else res[i] += num[k] * num[j];
            ++j;
            
            if(res[i] > 9) {
                if(i > 0) {
                    res[i - 1] += res[i] / 10;
                }
                res[i] = res[i] % 10;
                if(res[i - 1] > 9) {
                    if(i > 1) {
                        res[i - 2] += res[i - 1] / 10;
                    }
                    res[i - 1] = res[i - 1] % 10;
                }
            } 
        }
        
        if(res[i] != num[i]) {
            f = false;
            std::cout <<  n - i;
            break;
        }        
    }

    if(f) {
        std::cout << "OK";
    }


    return 0;
}