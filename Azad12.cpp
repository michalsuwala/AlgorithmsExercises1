#include <iostream>
#include <cmath>

double P(int i, int j) {
    return 30 - sqrt((i - 5) * (i - 5) + (j - 5) * (j - 5));
}

long divideConquer(int n_start, int n_end, int m, int a_start, int a_end) {
    int middle = n_start + (n_end - n_start) / 2;
    long max = 0, indMax = 0;
    for(int i = 0; i < m; i++) {
        if(P(middle, i) > max) {
            indMax = i;
            max = P(middle, i);
        }
        else {
            break;
        }
    }
    
    
    long nMax = -1, nInd;
    if(P(middle - 1, indMax) >= P(middle + 1, indMax) && middle - 1 >= a_start) {
        nMax = P(middle - 1, indMax);
        nInd = middle - 1;
    }
    else if(P(middle - 1, indMax) <= P(middle + 1, indMax) && middle + 1 <= a_end) {        
        nMax = P(middle + 1, indMax);
        nInd = middle + 1;
    }
    if(max < nMax) {
        if(nInd < middle && middle - 1 >= n_start) return divideConquer(n_start, middle - 1, m, a_start, a_end);
        else if(nInd < middle) return divideConquer(n_start - 1, middle - 1, m, a_start, a_end);
        else if(nInd > middle && middle + 1 <= n_end) return divideConquer(middle + 1, n_end, m, a_start, a_end);
        else return divideConquer(middle + 1, n_end + 1, m, a_start, a_end);
    }
    else {
        return floor(max);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cout << divideConquer(0, n - 1, m, 0, n - 1);
    return 0;
}