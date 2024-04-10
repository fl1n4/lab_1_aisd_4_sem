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
    Node* deepCopy(Node* node);
    bool destroyTree(Node* node);
};