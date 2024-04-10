#include <iostream>
#include <chrono>
#include <cstdlib>
#include <vector>
#include "BinaryTree.h"

size_t lcg() {
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

void fillTreeWithRandomNumbers(BinaryTree& tree, int size) {
    for (int i = 0; i < size; ++i) {
        size_t random_num = lcg();
        tree.insert(static_cast<int>(random_num));
    }
}

void fillVectorWithRandomNumbers(std::vector<int>& vec, int size) {
    vec.clear();
    for (int i = 0; i < size; ++i) {
        size_t random_num = lcg();
        vec.push_back(static_cast<int>(random_num));
    }
}

bool searchVector(const std::vector<int>& vec, int target) {
    return std::find(vec.begin(), vec.end(), target) != vec.end();
}

int main() {
    const int sizes[] = { 1000, 10000, 100000 };
    int num_trials = 100;

    for (int size : sizes) {
        double total_insert_time = 0;

        for (int i = 0; i < num_trials; ++i) {
            BinaryTree tree;
            auto start_insert_time = std::chrono::high_resolution_clock::now();
            fillTreeWithRandomNumbers(tree, size);
            auto end_insert_time = std::chrono::high_resolution_clock::now();
            total_insert_time += std::chrono::duration<double, std::milli>(end_insert_time - start_insert_time).count();
        }

        double average_time = total_insert_time / num_trials;
        std::cout << "Average time to fill a tree with size " << size << ": " << average_time << " milliseconds" << std::endl;
    }

    num_trials = 1000;

    for (int size : sizes) {
        double total_search_time = 0;

        for (int i = 0; i < num_trials; ++i) {
            BinaryTree tree;
            fillTreeWithRandomNumbers(tree, size);
            size_t random_num = lcg();
            auto start_insert_time = std::chrono::high_resolution_clock::now();
            tree.contains(static_cast<int>(random_num));
            clock_t end_time = clock();
            auto end_insert_time = std::chrono::high_resolution_clock::now();
            total_search_time += std::chrono::duration<double, std::milli>(end_insert_time - start_insert_time).count();
        }

        double average_time = total_search_time / num_trials;
        std::cout << "Average time to search a tree with size " << size << ": " << average_time << " milliseconds" << std::endl;
    }

    for (int size : sizes) {
        double total_insert_time = 0;
        double total_erase_time = 0;

        for (int i = 0; i < num_trials; ++i) {
            BinaryTree tree;
            fillTreeWithRandomNumbers(tree, size);

            size_t random_insert_num = lcg();
            auto start_insert_time = std::chrono::high_resolution_clock::now();
            tree.insert(static_cast<int>(random_insert_num));
            auto end_insert_time = std::chrono::high_resolution_clock::now();
            total_insert_time += std::chrono::duration<double, std::milli>(end_insert_time - start_insert_time).count();

            size_t random_erase_num = lcg();
            auto start_erase_time = std::chrono::high_resolution_clock::now();
            tree.erase(static_cast<int>(random_erase_num));
            auto end_erase_time = std::chrono::high_resolution_clock::now();
            total_erase_time += std::chrono::duration<double, std::milli>(end_erase_time - start_erase_time).count();
        }

        double average_insert_erase_time = (total_insert_time+total_erase_time) / num_trials;
        std::cout << "Average time to insert&erase in a tree with size " << size << ": " << average_insert_erase_time << " milliseconds" << std::endl;
    }

    num_trials = 100;

    for (int size : sizes) {
        double total_insert_time = 0;

        for (int i = 0; i < num_trials; ++i) {
            std::vector<int> vec;
            auto start_insert_time = std::chrono::high_resolution_clock::now();
            fillVectorWithRandomNumbers(vec, size);
            auto end_insert_time = std::chrono::high_resolution_clock::now();
            total_insert_time += std::chrono::duration<double, std::milli>(end_insert_time - start_insert_time).count();
        }

        double average_time = total_insert_time / num_trials;
        std::cout << "Average time to fill a vector with size " << size << ": " << average_time << " milliseconds" << std::endl;
    }

    num_trials = 1000;

    for (int size : sizes) {
        double total_search_time = 0;

        for (int i = 0; i < num_trials; ++i) {
            std::vector<int> vec;
            size_t random_search_num = lcg();
            fillVectorWithRandomNumbers(vec, size);
            auto start_search_time = std::chrono::high_resolution_clock::now();
            searchVector(vec, static_cast<int>(random_search_num));
            auto end_search_time = std::chrono::high_resolution_clock::now();
            total_search_time += std::chrono::duration<double, std::milli>(end_search_time - start_search_time).count();
        }

        double average_time = total_search_time / num_trials;
        std::cout << "Average time to search a vector with size " << size << ": " << average_time << " milliseconds" << std::endl;
    }

    for (int size : sizes) {
        double total_insert_time = 0;
        double total_erase_time = 0;

        for (int i = 0; i < num_trials; ++i) {
            std::vector<int> vec;
            fillVectorWithRandomNumbers(vec, size);

            size_t random_insert_num = lcg();
            auto start_insert_time = std::chrono::high_resolution_clock::now();
            vec.push_back(static_cast<int>(random_insert_num));
            auto end_insert_time = std::chrono::high_resolution_clock::now();
            total_insert_time += std::chrono::duration<double, std::milli>(end_insert_time - start_insert_time).count();

            size_t random_erase_num = lcg();
            auto start_erase_time = std::chrono::high_resolution_clock::now();
            auto it = std::find(vec.begin(), vec.end(), static_cast<int>(random_erase_num));
            if (it != vec.end()) {
                vec.erase(it);
            }
            auto end_erase_time = std::chrono::high_resolution_clock::now();
            total_erase_time += std::chrono::duration<double, std::milli>(end_erase_time - start_erase_time).count();
        }

        double average_insert_erase_time = (total_insert_time+total_erase_time) / num_trials;
        std::cout << "Average time to insert&erase in a vector with size " << size << ": " << average_insert_erase_time << " milliseconds" << std::endl;
    }

    return 0;
}