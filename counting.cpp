#include "counting.h"
#include <vector>
#include <algorithm>

void sortCounting(std::vector<int>& arr) {
    if (arr.empty()) return;
    int max_val = *std::max_element(arr.begin(), arr.end());
    std::vector<size_t> count(static_cast<size_t>(max_val) + 1, 0);

    for (int x : arr) {
        count[static_cast<size_t>(x)]++;
    }

    size_t index = 0;
    for (size_t i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            arr[index++] = static_cast<int>(i);
            count[i]--;
        }
    }
}