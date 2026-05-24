#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include <algorithm> // untuk std::sort bawaan (membantu membuat skenario)

// Include file algoritma kalian
#include "bubble.h"
// #include "selection.h"  // Uncomment jika file temanmu sudah ada
// #include "quick.h"      // Uncomment jika file temanmu sudah ada

using std::cout;
using std::cin;
using std::vector;
using std::string;

// --- FUNGSI BENCHMARK ---
void runBenchmark(const string& namaAlgoritma, void (*fungsiSort)(vector<int>&), vector<int> data) {
    cout << ">> Menjalankan " << namaAlgoritma << "... ";
    
    auto start = std::chrono::high_resolution_clock::now();
    fungsiSort(data); 
    auto end = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    cout << "Selesai! Waktu: " << duration.count() << " ms\n";
}

// --- FUNGSI GENERATOR DATA ---
vector<int> generateData(size_t n, int pilihanKondisi) {
    vector<int> data(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100000);

    // 1. Isi dengan data acak dulu
    for (size_t i = 0; i < n; i++) {
        data[i] = dist(gen);
    }

    // 2. Ubah sesuai kondisi yang dipilih user
    if (pilihanKondisi == 2) {
        // Kondisi Best Case: Data sudah urut dari kecil ke besar
        std::sort(data.begin(), data.end());
    } else if (pilihanKondisi == 3) {
        // Kondisi Worst Case: Data urut terbalik (besar ke kecil)
        std::sort(data.begin(), data.end(), std::greater<int>());
    }
    
    return data;
}

// --- PROGRAM UTAMA ---
int main() {
    int input_n;
    int pilihanKondisi;

    cout << "==========================================\n";
    cout << "  BENCHMARK ALGORITMA SORTING KELOMPOK X  \n";
    cout << "==========================================\n\n";

    // 1. Tentukan Jumlah Data
    cout << "Masukkan jumlah data yang ingin diuji (misal: 10000): ";
    if (!(cin >> input_n) || input_n <= 0) {
        cout << "Error: Input harus angka positif!\n";
        return 1;
    }
    size_t n = static_cast<size_t>(input_n);

    // 2. Pilih Kondisi Data (Ini yang bikin presentasi kalian keren)
    cout << "\nPilih kondisi awal data:\n";
    cout << "1. Data Acak (Random)\n";
    cout << "2. Data Sudah Terurut (Best Case)\n";
    cout << "3. Data Terurut Terbalik (Worst Case)\n";
    cout << "Pilihan (1/2/3): ";
    cin >> pilihanKondisi;

    if (pilihanKondisi < 1 || pilihanKondisi > 3) {
        cout << "Pilihan tidak valid, otomatis menggunakan Data Acak.\n";
        pilihanKondisi = 1;
    }

    cout << "\n[ Mempersiapkan " << n << " data... ]\n";
    vector<int> dataUtama = generateData(n, pilihanKondisi);
    cout << "[ Data siap! Memulai Benchmark... ]\n\n";

    // 3. Panggil dan uji semua algoritma dengan data yang sama
    cout << "--- HASIL UJI KECEPATAN ---\n";
    
    // Bubble Sort (Pekerjaanmu)
    //runBenchmark("Bubble Sort   ", sortBubble, dataUtama);
    
    /* 
    // SELECTION SORT (Pekerjaan Temanmu)
    // Uncomment baris di bawah jika function selection sort sudah di-include
    // runBenchmark("Selection Sort", sortSelection, dataUtama);
    
    // QUICK SORT (Pekerjaan Temanmu)
    // Uncomment baris di bawah jika function quick sort sudah di-include
    // runBenchmark("Quick Sort    ", sortQuick, dataUtama);
    */

    cout << "\n==========================================\n";
    cout << "Pengujian Selesai!\n";
    
    return 0;
}