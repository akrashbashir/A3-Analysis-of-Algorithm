#include <iostream>

void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    // Array for best case scenario (already sorted)
    std::vector<int> bestCase(1000);
    for (int i = 0; i < 1000; ++i) {
        bestCase[i] = i;
    }

    auto start = std::chrono::high_resolution_clock::now();
    bubbleSort(bestCase);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Bubble Sort (Best Case): " << duration.count() << " seconds" << std::endl;
    return 0;
}
