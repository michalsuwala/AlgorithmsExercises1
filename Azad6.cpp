#include <iostream>
#include <vector>
#include <queue>

struct Monkey {
    char m1;
    int m2;
    std::vector<Monkey*> children;

    Monkey(char m1, int m2) : m1(m1), m2(m2) {}
    ~Monkey() {
        for(Monkey* child : children) {
            delete child;
        }
    }
};

void preorder(Monkey *monkey) {
    std::cout << monkey->m1;
    for(Monkey *child : monkey->children) {
            preorder(child);
        }
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int k, n;
    int m2;
    char m1;

    std::cin >> k;
    for(int i = 0; i < k; i++) {
        std::cin >> n;
        std::cin >> m1 >> m2;
        
        Monkey *root = new Monkey(m1, m2);
        Monkey  *current = root;
        
        std::queue<Monkey*> parents;
        int size = m2;
        std::vector<Monkey> monkeys;

        for(int j = 1; j < n; j++) {
            std::cin >> m1 >> m2;
            Monkey *m = new Monkey(m1, m2);
            parents.push(m);
            if(size > 0) {
                current->children.push_back(m);
                size--;
            }
            else {
                current = parents.front();
                parents.pop();
                size = current->m2;
                current->children.push_back(m);
                size--;
            }
        }
        preorder(root);
        delete root;
        std::cout << "\n";        
    }
    return 0;
}