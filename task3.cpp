#include <vector>
#include <iostream>
#include "BinaryTree.h"

std::vector<int> getUniqueElements(const std::vector<int>& input) {
    std::vector<int> result;
    BinaryTree tree_unique;
    BinaryTree tree_duplicates;

    for (auto& item : input)
    {
        if (!tree_unique.contains(item))
        {
            tree_unique.insert(item);
        }
        else
        {
            tree_duplicates.insert(item);
        }
    }
    for (auto& item : input )
    {
        if (!tree_duplicates.contains(item))
        {
            result.push_back(item);
        }
    }
    return result;
}

int main() {
    std::vector<int> input = { 3, 2, 2, 2, 4};

    std::vector<int> uniqueElements = getUniqueElements(input);

    std::cout << "Unique Elements: ";
    for (int num : uniqueElements) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}