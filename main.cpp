#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include "bubble.h"
//#include "counting.h"
#include "quick.h"

using namespace std;
using namespace std::chrono;

void clearScreen() {
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear"); 
    #endif 
}

void printDataPreview(const vector<int>& data, const string& judul) {
    cout << judul << " :\n[ ";
    size_t limit = min(data.size(), static_cast<size_t>(20));
    
    for (size_t i = 0; i < limit; i++) {
        cout << data[i];
        if (i < limit - 1) cout << ", ";
    }
    
    if (data.size() > limit) {
        cout << " ... (dan " << data.size() - limit << " angka lainnya)";
    }
    cout << " ]\n";
}

long long runBenchmark(const string& namaAlgoritma, void (*fungsiSort)(vector<int>&), vector<int> data) {
    cout << "\n======================================================\n";
    cout << "  PENGUJIAN " << namaAlgoritma << "\n";
    cout << "======================================================\n";
    
    printDataPreview(data, ">> Data Sebelum Di-sort");
    
    auto start = high_resolution_clock::now();
    fungsiSort(data); 
    auto end = high_resolution_clock::now();
    
    auto duration = duration_cast<microseconds>(end - start); 
    
    cout << "\n";
    printDataPreview(data, ">> Data Setelah Di-sort");
    
    cout << "------------------------------------------------------\n";
    cout << "=> Waktu Eksekusi " << namaAlgoritma << " : " << duration.count() << " us\n";
    cout << "------------------------------------------------------\n";
    
    return duration.count();
}

vector<int> generateRandomData(size_t n) {
    vector<int> data(n);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100000);

    for (size_t i = 0; i < n; i++) data[i] = dist(gen);
    
    return data;
}

int main() {
    int input_n;

    clearScreen();

    cout << "======================================================\n";
    cout << "                  BENCHMARK SORTING                   \n";
    cout << "======================================================\n\n";

    cout << "Masukkan jumlah data yang ingin di uji : ";
    if (!(cin >> input_n) || input_n <= 0) return 1;
    size_t n = static_cast<size_t>(input_n);

    cout << "\n[*] Mempersiapkan " << n << " data acak...\n";
    vector<int> dataUtama = generateRandomData(n);
    cout << "[*] Data siap! Memulai pengujian satu per satu...\n";

    // PENGUJIAN SATU PER SATU
    long long tBubble   = runBenchmark("BUBBLE SORT", sortBubble, dataUtama);
    //long long tCounting = runBenchmark("COUNTING SORT", sortCounting, dataUtama);
    long long tQuick    = runBenchmark("QUICK SORT", sortQuick, dataUtama);
    //long long tQuick    = runBenchmark("QUICK SORT", sortQuick, dataUtama);

    cout << "\n======================================================\n";
    cout << "                     KESIMPULAN                       \n";
    cout << "======================================================\n";

    vector<pair<long long, string>> hasil = {
        {tBubble, "BUBBLE SORT"},
        //{tCounting, "COUNTING SORT"},
        {tQuick, "QUICK SORT"}
        //{tQuick, "QUICK SORT"}
    };

    sort(hasil.begin(), hasil.end());

    cout << "RANK | ALGORITMA       | WAKTU EKSEKUSI\n";
    cout << "------------------------------------------------------\n";
    for (int i = 0; i < hasil.size(); i++) {
        cout << (i + 1) << "    | " << left << setw(15) << hasil[i].second 
             << " | " << hasil[i].first << " us" << endl;
    }
    cout << "======================================================\n\n";

    return 0;
}