#pragma once

class BinaryTree {
private:
    struct Node {
        int info;
        Node* left;
        Node* right;
        Node(const int k) : info(k), left(nullptr), right(nullptr) {}
    };
    Node* root;

public:
    BinaryTree();
    BinaryTree(const BinaryTree& other);
    ~BinaryTree();
    BinaryTree& operator=(const BinaryTree& other);

    void print();
    bool insert(int key);
    bool contains(int key);
    bool erase(int key);

    Node* deepCopy(Node* node);
    Node* findMinElement(Node* node);
    bool destroyTree(Node* node);
    bool insertRecursive(Node*& node, int key);
    void inorderPrint(Node* node);
    bool containsRecursive(Node* node, int key);
    bool eraseRecursive(Node*& node, int key);
};