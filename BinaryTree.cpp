#include "BinaryTree.h"
#include <iostream>

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
        return true; // Успешно уничтожено
    }
    return false; // Уже пустое дерево или узел был nullptr
}

bool BinaryTree::insertRecursive(Node*& node, int key) {
    if (node == nullptr) {
        node = new Node(key);
        return true;
    }
    else if (key < node->info) {
        return insertRecursive(node->left, key);
    }
    else if (key > node->info) {
        return insertRecursive(node->right, key);
    }
    else {
        return false;
    }
}

void BinaryTree::inorderPrint(Node* node) {
    if (node != nullptr) {
        inorderPrint(node->left);
        std::cout << node->info << " ";
        inorderPrint(node->right);
    }
}

bool BinaryTree::containsRecursive(Node* node, int key) {
    if (node == nullptr) {
        return false;
    }
    else if (key == node->info) {
        return true;
    }
    else if (key < node->info) {
        return containsRecursive(node->left, key);
    }
    else {
        return containsRecursive(node->right, key);
    }
}

bool BinaryTree::eraseRecursive(Node*& node, int key) {
    if (node == nullptr) {
        return false;
    }
    else if (key < node->info) {
        return eraseRecursive(node->left, key);
    }
    else if (key > node->info) {
        return eraseRecursive(node->right, key);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node* minRight = findMinElement(node->right);
            node->info = minRight->info;
            eraseRecursive(node->right, minRight->info);
        }
        return true;
    }
}

BinaryTree::Node* BinaryTree::findMinElement(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(const BinaryTree& other) {
    root = deepCopy(other.root);
}

BinaryTree::~BinaryTree() {
    destroyTree(root);
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other) {
    if (this != &other) {
        delete root;
        root = deepCopy(other.root);
    }
    return *this;
}

void BinaryTree::print() {
    inorderPrint(root);
}

bool BinaryTree::insert(int key) {
    if (root == nullptr) {
        root = new Node(key);
        return true;
    }
    else {
        return insertRecursive(root, key);
    }
}

bool BinaryTree::contains(int key) {
    return containsRecursive(root, key);
}

bool BinaryTree::erase(int key) {
    return eraseRecursive(root, key);
}