#include <iostream>
#include <vector>
#include <string>

const int MIN_DEGREE = 10; // Minimalny stopień B-drzewa
const int MAX_DEGREE = 20; // Maksymalny stopień B-drzewa

class BTreeNode {
private:
    std::vector<std::string> keys;
    std::vector<std::string> values;
    std::vector<BTreeNode*> children;
    bool leaf;
public:
    BTreeNode(bool leaf);
    void insertNonFull(const std::string& key, const std::string& value);
    std::pair<std::string, bool> search(const std::string& key);
    friend class BTree;
};

class BTree {
private:
    BTreeNode* root;
    int t; // Minimalny stopień B-drzewa
public:
    BTree(int t);
    void insert(const std::string& key, const std::string& value);
    std::pair<std::string, bool> search(const std::string& key);
};

// Implementacja metod BTreeNode

BTreeNode::BTreeNode(bool leaf) {
    this->leaf = leaf;
}

void BTreeNode::insertNonFull(const std::string& key, const std::string& value) {
    int i = keys.size() - 1;
    if (leaf) {
        while (i >= 0 && key < keys[i]) {
            i--;
        }
        keys.insert(keys.begin() + i + 1, key);
        values.insert(values.begin() + i + 1, value);
    } else {
        while (i >= 0 && key < keys[i]) {
            i--;
        }
        if (children[i + 1]->keys.size() == 2 * MAX_DEGREE - 1) {
            // Podział węzła, gdy jest pełen
            BTreeNode* child = children[i + 1];
            BTreeNode* newNode = new BTreeNode(child->leaf);
            for (int j = 0; j < MAX_DEGREE - 1; j++) {
                newNode->keys.push_back(child->keys[j + MAX_DEGREE]);
                newNode->values.push_back(child->values[j + MAX_DEGREE]);
            }
            if (!child->leaf) {
                for (int j = 0; j < MAX_DEGREE; j++) {
                    newNode->children.push_back(child->children[j + MAX_DEGREE]);
                }
            }
            child->keys.resize(MAX_DEGREE - 1);
            child->values.resize(MAX_DEGREE - 1);
            child->children.resize(MAX_DEGREE);
            children.insert(children.begin() + i + 1, newNode);
            keys.insert(keys.begin() + i, child->keys[MAX_DEGREE - 1]);
            values.insert(values.begin() + i, child->values[MAX_DEGREE - 1]);
        }
        children[i + 1]->insertNonFull(key, value);
    }
}

std::pair<std::string, bool> BTreeNode::search(const std::string& key) {
    int i = 0;
    while (i < keys.size() && key > keys[i]) {
        i++;
    }
    if (i < keys.size() && key == keys[i]) {
        return {values[i], true};
    }
    if (leaf) {
        return {"", false};
    }
    return children[i]->search(key);
}

// Implementacja metod BTree

BTree::BTree(int t) {
    this->t = t;
    root = new BTreeNode(true);
}

void BTree::insert(const std::string& key, const std::string& value) {
    if (root->keys.size() == 2 * t - 1) {
        // Tworzenie nowego korzenia, gdy poprzedni jest pełny
        BTreeNode* newNode = new BTreeNode(false);
        newNode->children.push_back(root);
        newNode->insertNonFull(key, value);
        root = newNode;
    } else {
        root->insertNonFull(key, value);
    }
}

std::pair<std::string, bool> BTree::search(const std::string& key) {
    return root->search(key);
}

int main() {
    int n;
    std::cin >> n;
    
    BTree btree(MIN_DEGREE);

    for (int i = 0; i < n; ++i) {
        std::string operation;
        std::cin >> operation;

        if (operation == "hasło") {
            std::string key, value;
            std::cin >> key;
            std::getline(std::cin >> std::ws, value);
            btree.insert(key, value);
        } else if (operation == "hasło") {
            std::string key;
            std::cin >> key;
            auto result = btree.search(key);
            if (result.second) {
                std::cout << result.first << std::endl;
            } else {
                std::cout << "BRAK" << std::endl;
            }
        }
    }

    return 0;
}
