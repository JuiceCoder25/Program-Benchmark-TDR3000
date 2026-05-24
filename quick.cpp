#include "quick.h"
#include <algorithm>

using namespace std;

void sortQuick(vector<int>& arr, int low, int high) {
    if (low >= high) return; 

    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < arr[high]) { 
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[i], arr[high]); 

    sortQuick(arr, low, i - 1); 
    sortQuick(arr, i + 1, high); 
}

void sortQuick(vector<int>& arr) {
    if (!arr.empty()) sortQuick(arr, 0, arr.size() - 1);
}