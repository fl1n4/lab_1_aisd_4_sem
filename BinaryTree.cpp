#include "BinaryTree.h"
#include "iostream"

BinaryTree::Node* BinaryTree::deepCopy(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }
    else {
        Node* new_node = new Node(node->info);
        new_node->left = deepCopy(node->left);
        new_node->right = deepCopy(node->right);
        return new_node;
    }
}

bool BinaryTree::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other) {
    if (this != &other) { 
        delete root;
        root = deepCopy(other.root);
    }
    return *this;
}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(const BinaryTree& other) {
    root = deepCopy(other.root);
}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}