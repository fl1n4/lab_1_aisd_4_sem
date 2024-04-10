#include <vector>
#include <iostream>
#include "BinaryTree.h"

std::vector<int> getUniqueElements(const std::vector<int>& input) {
    std::vector<int> temp;
    std::vector<int> result;
    BinaryTree tree;
    for (int element : input) {
        bool flag = tree.insert(element);
        if (!flag) {
            temp.push_back(element);
        }
    }
    for (int element : temp)
    {
        tree.erase(element);
    }
    tree.fillVector(tree.getRoot(), result);
    return result;
}

int main() {
    std::vector<int> input = { 3, 2, 2, 4};

    std::vector<int> uniqueElements = getUniqueElements(input);

    std::cout << "Unique Elements: ";
    for (int num : uniqueElements) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}