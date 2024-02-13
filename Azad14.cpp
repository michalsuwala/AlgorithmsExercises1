#include <iostream>
#include <vector>
#include <algorithm>

struct Program{
    int start;
    int end;
    Program(int s, int e) : start(s), end(e) {}
};

bool compS(Program *a, Program *b) {
    return a->start > b->start;
}

bool compE(Program *a, Program *b) {
    return a->end > b->end;
}


int main() {
    int t;
    for(int i = 0; i < t; i++) {
        int n, c, d;
        std::cin >> n >> c >> d;
        int rent = c - d;
        //std::vector<Program*> programS;
        std::vector<Program*> programE;
        for(int j = 0; j < n; j++) {
            int t1, t2;
            std::cin >> t1 >> t2;
            Program *p = new Program(t1, t2);
            //programS.push_back(p);
            programE.push_back(p);
        }
        //std::sort(programS.begin(), programS.end(), compS);
        std::sort(programE.begin(), programE.end(), compE);
        int last;
        for(Program *p: programE) {
            
        }
    }
     return 0;
}