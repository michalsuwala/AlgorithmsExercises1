#include <iostream>
#include <vector>
#include <string>
#include <queue>

struct Point {
    int i;
    int j;
    char c;
    Point(int i, int j, char c) : i(i), j(j), c(c) {}
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;
    int start;
    std::cin >> n >> m;
    std::vector<std::string> map(n);
    std::queue<Point*> q;
    int level[n * m];
    int monitored[n * m];

    for(int i = 0; i < n; i++) {
        std::cin >> std::ws;
        std::getline(std::cin, map[i]);    
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            level[i * m + j] = -1;
            monitored [i * m + j] = 0;
            if(map[i][j] == 'S') {
                Point *start = new Point(i, j, 'S');
                q.push(start);
                level[i * m + j] = 0;
            }
            
        }
    }

    int currentI, currentJ;
    int cLvl = 0;
    int found = -5;
    int fMon;
    int index;
    while(!q.empty()) {
        currentI = q.front()->i;
        currentJ = q.front()->j;
        index = currentI * m + currentJ;
        cLvl = level[currentI * m + currentJ];
        if(cLvl == found) {
            break;
        } 
        q.pop();

        if(currentJ > 0 && (level[index - 1] == -1 || (monitored[index - 1] > monitored[index] && level[index - 1] == cLvl + 1))) {
            char c = map[currentI][currentJ - 1];
            if(c == '.' || c == 'M' || c == 'X') {
                if(level[index - 1] == -1) {
                    Point *p = new Point(currentI, currentJ - 1, c);
                    q.push(p);
                    level[index - 1] = cLvl + 1;
                }
                if(c == 'M') monitored[index - 1] = monitored[index] + 1;
                else monitored[index - 1] = monitored[index];
                if(c == 'X') {
                    found = cLvl + 1;
                    fMon = monitored[index - 1];
                }
            }
        }
        if(currentJ < m - 1 && (level[index + 1] == -1 || (monitored[index + 1] > monitored[index] && level[index + 1] == cLvl + 1))) {
            char c = map[currentI][currentJ + 1];
            if(c == '.' || c == 'M' || c == 'X') {
                if(level[index + 1] == -1) {
                    Point *p = new Point(currentI, currentJ + 1, c);
                    q.push(p);
                    level[index + 1] = cLvl + 1;
                }
                if(c == 'M') monitored[index + 1] = monitored[index] + 1;
                else monitored[index + 1] = monitored[index];
                if(c == 'X') {
                    found = cLvl + 1;
                    fMon = monitored[index + 1];
                }
            }
        }
        if(currentI > 0 && (level[index - m] == -1 || (monitored[index - m] > monitored[index] && level[index - m] == cLvl + 1))) {
            char c = map[currentI - 1][currentJ];
            if(c == '.' || c == 'M' || c == 'X') {
                if(level[index - m] == -1) {
                    Point *p = new Point(currentI - 1, currentJ, c);
                    q.push(p);
                    level[index - m] = cLvl + 1;
                }
                if(c == 'M') monitored[index - m] = monitored[index] + 1;
                else monitored[index - m] = monitored[index];
                if(c == 'X') {
                    found = cLvl + 1;
                    fMon = monitored[index - m];
                }
            }
        }
        if(currentI < n - 1 && (level[index + m] == -1 || (monitored[index + m] > monitored[index] && level[index + m] == cLvl + 1))) {
            char c = map[currentI + 1][currentJ];
            if(c == '.' || c == 'M' || c == 'X') {
                if(level[index + m] == -1) {
                    Point *p = new Point(currentI + 1, currentJ, c);
                    q.push(p);
                    level[index + m] = cLvl + 1;
                }
                if(c == 'M') monitored[index + m] = monitored[index] + 1;
                else monitored[index + m] = monitored[index];
                if(c == 'X') {
                    found = cLvl + 1;
                    fMon = monitored[index + m];
                }
            }
        }
    }
    
    std::cout << found << " " << fMon;
    

    return 0;
}