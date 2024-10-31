#include <iostream>
#include <chrono>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

int main() {
    // Array for average case scenario (random order)
    std::vector<int> averageCase(1000);
    for (int i = 0; i < 1000; ++i) {
        averageCase[i] = rand() % 1000;
    }

    auto start = std::chrono::high_resolution_clock::now();
    selectionSort(averageCase);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Selection Sort (Average Case): " << duration.count() << " seconds" << std::endl;
    return 0;
}
