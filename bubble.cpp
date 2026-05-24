#include "bubble.h"
#include <algorithm>

using namespace std;

void sortBubble(vector<int>& arr) {
    size_t n = arr.size();
    if (n <= 1) return;
    
    bool swapped;
    for (size_t i = 0; i < n - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}