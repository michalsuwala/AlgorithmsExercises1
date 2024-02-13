#include <iostream>

struct Crate {
    double *bottles; 
    double filled;     
    int m;
    Crate *next;             

    Crate(double *b, int m) : bottles(b), m(m) {
        filled = 0.0;
        for(int i = 0; i < m; i++) {
            filled += b[i];
        }
        next = nullptr;
    }

    Crate() {}

    ~Crate() {
        delete[] bottles;
    }
};

struct Bucket {
    Crate *head;
    Crate *last;

    Bucket() : head(nullptr), last(nullptr) {}

    void insert(Crate *crate) {
        if(head == nullptr || head->filled < crate->filled) {
            crate->next = head;
            head = crate;
        } 
        else {
            Crate *current = head;
            while(current->next != nullptr && current->next->filled >= crate->filled) {
                current = current->next;
            }
            crate->next = current->next;
            current->next = crate;
        }
    }
};



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    int n, m, p;
    std::cin >> n >> m >> p;
        
    Bucket *buckets = new Bucket[(m + 1) * n];
    Crate *c;
    int bSize[(m + 1) * n] = {0};

    for(int i = 0; i < n; i++) {
        double *bottles = new double[m];
        for(int j = 0; j < m; j++) {
            std::cin >> bottles[j];
        }   
        c = new Crate(bottles, m);
        buckets[int(c->filled * n)].insert(c);
        
        bSize[int(c->filled * n)]++;
    }

    
    for(int i = m * n; i >= 0; i--) {
        if(buckets[i].head) {
            c = buckets[i].head;
        }
        for(int j = 0; j < bSize[i]; j++) {
            if(!p) {
                delete[] buckets;
                return 0;
            }
            
            for(int k = 0; k < m; k++) {
                std::cout << c->bottles[k]<< " ";
            }
            if(c->next) c = c->next;
            p--;
            std::cout << '\n';
        }
    }

    delete[] buckets;

    return 0;
}