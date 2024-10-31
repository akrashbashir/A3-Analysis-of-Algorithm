#include <iostream>
#include <chrono>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    // Array for average case scenario (random order)
    std::vector<int> averageCase(1000);
    for (int i = 0; i < 1000; ++i) {
        averageCase[i] = rand() % 1000;
    }

    auto start = std::chrono::high_resolution_clock::now();
    quickSort(averageCase, 0, averageCase.size() - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Quick Sort (Average Case): " << duration.count() << " seconds" << std::endl;
    return 0;
}
