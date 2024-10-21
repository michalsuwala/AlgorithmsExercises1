#include<bits/stdc++.h>

std::set<int> s;

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int item) {
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key >= node->key)
        node->right = insert(node->right, key);
    return node;
}

void cut(Node* &root, int min, int max) {
    if (root) {
        if (root->key < min) {
            root = root->right;
            cut(root, min, max);
            
        }
        else if (root->key > max) {
            root = root->left;
            cut(root, min, max);
            
        }
        else {
            cut(root->left, min, max);
            cut(root->right, min, max);
        }
    }
}

void inorder(Node* root, int k, bool &found, std::pair<int, int> &p) {
    if (root){
        if (s.find(k - root->key) != s.end()) {
            found = true;
            if (abs(k - root->key - root->key) < p.second - p.first) {
                p.first = std::min(k - root->key, root->key);
                p.second = std::max(k - root->key, root->key);
            }
        }
        else {
            s.emplace(root->key);
            inorder(root->left, k, found, p);
            inorder(root->right, k, found, p);
        }
    }
}

int main() {
    int n, a, b, k;
    std::cin >> n;

    std::vector<int> clues(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> clues[i];
    }

    std::cin >> a >> b >> k;

    Node *root = NULL;
    root = insert(root, clues[0]);
    std::pair<int, int> res = std::make_pair(0, INT_MAX);
    for (int i = 1; i < n; ++i) {
        root = insert(root, clues[i]);
    }

    cut(root, a, b);
    bool found = false;
    inorder(root, k, found, res);


    if (!found) {
        std::cout << "NIE ZNALEZIONO";
    } else {
        std::cout << res.first << " " << res.second;
    }

    return 0;
}