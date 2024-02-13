#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long n;
    int k;
    std::cin >> n;

    std::string names[n];
    int dist[n];
    int ord[n];

    std::string temps;
    int tempi, tempo;
    int j;
    for(int i = 0; i < n; i++) {
        std::cin >> std::ws;
        std::getline(std::cin, names[i], ' ');
        std::cin >> dist[i];
        ord[i] = i;
        j = i;
        while(j) {
            if(dist[(j - 1) / 2] < dist[j]) {
                tempi = dist[j];
                temps = names[j];
                tempo = ord[j];
                dist[j] = dist[(j - 1) / 2];
                names[j] = names[(j - 1) / 2];
                ord[j] = ord[(j - 1) / 2];
                dist[(j - 1) / 2] = tempi;
                names[(j - 1) / 2] = temps;
                ord[(j - 1) / 2] = tempo;
            }
            j = (j - 1) / 2;
        }
    }


    std::cin >> k;
    int m = n;

    while(m > 1) {
        if(dist[0] <= k) {
            std::cout << names[0] << ' ';
            k -= dist[0];
        }
        if(k <= 0) {
            break;
        }
        dist[0] = dist[m - 1];
        names[0] = names[m - 1];
        ord[0] = ord[m - 1];
        m--;

        j = 0;
        while(j * 2 + 1 < m) {
            int l = j;
            if(j * 2 + 2 < m && (dist[j * 2 + 2] > dist[l] || dist[j * 2 + 2] == dist[l] && ord[j * 2 + 2] < ord[l])) {
                l = j * 2 + 2;
            }
            if(dist[j * 2 + 1] > dist[l] || dist[j * 2 + 1] == dist[l] && ord[j * 2 + 1] < ord[l]) {
                l = j * 2 + 1;
            }
            if(l == j) break;

            tempi = dist[j];
            temps = names[j];
            tempo = ord[j];
            dist[j] = dist[l];
            names[j] = names[l];
            ord[j] = ord[l];
            dist[l] = tempi;
            names[l] = temps;
            ord[l] = tempo;

            j = l;
        }
    }
    
    if(dist[0] <= k) {
            std::cout << names[0];
    }
    
    return 0;
}