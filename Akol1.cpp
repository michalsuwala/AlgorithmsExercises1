#include <iostream>

struct Node {
    Node *next;
    Node *previous;
    int val;

    Node(int el) : val(el), previous(nullptr), next(nullptr) {} 
};

class List {
    Node *head;
    Node *tail;
    int size;
    
    public:
    List() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void first() {
        if(head) {
            std::cout << head->val << '\n';
        }
        else {
            std::cout << "PUSTA" << '\n';
        }
    }

    void last()  {
        if(tail) {
            std::cout << tail->val << '\n';
        }
        else {
            std::cout << "PUSTA" << '\n';
        }
    }

    void getSize() {
        std::cout << size << '\n';
    }
     
    void addFront(int el) {
        size++;
        Node *node = new Node(el);
        if(head) {
            head->previous = node;
            node->next = head;
            head = node;
            return;
        }
        head = node;
        tail = node;       
    }

    void addLast(int el) {
        size++;
        Node *node = new Node(el);
        if(!head) {
            head = node;
            tail = node;
            return;
        }
        node->previous = tail;
        tail->next = node;
        tail = node;
    }

    void removeFirst() {
        if(head) {
            size--;
            if(head->next) {
                head = head->next;
                head->previous = nullptr;
                return;
            }
            head = nullptr;
            tail = nullptr;
        }
        else {
            std::cout << "PUSTA" << '\n';
        }
    }

    void removeLast() {
        if(head) {
            size--;
            if(head == tail) {
                head = nullptr;
                tail = nullptr;
                return;
            }
            tail = tail->previous;
            tail->next = nullptr;
        }
        else {
            std::cout << "PUSTA" << '\n';
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int op;
    List list = List();

    for(int i = 0; i < n; i++) {
        std::cin >> op;
        if(op == 1) {
            list.first();
        }
        else if(op == 2) {
            list.last();
        }
        else if(op == 3) {
            list.getSize();
        }
        else if(op == 4) {
            std::cin >> op;
            list.addFront(op);
        }
        else if(op == 5) {
            std::cin >> op;
            list.addLast(op);
        }
        else if(op == 6) {
            list.removeFirst();
        }
        else if(op == 7) {
            list.removeLast();
        }
    }
    
    return 0;
}