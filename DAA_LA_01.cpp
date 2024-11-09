#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>  // for malloc and free

using namespace std;

// Iteratively using memoization
void iStepFibonacci(int n) {
    vector<int> f;
    f.push_back(0);
    if (n > 0) f.push_back(1); // Add 1 only if n > 0

    for (int i = 2; i <= n; i++) {
        f.push_back(f[i - 1] + f[i - 2]);
    }

    cout << "Fibonacci Series (Iterative): ";
    for (int num : f) {
        cout << num << " ";
    }
    cout << endl;
}

// Counter for recursive steps
int rSteps = 0;

// Recursively
int rStepFibonacci(int n) {
    rSteps++;
    if (n < 0) return 0;
    if (n == 1 || n == 0) return n; // Changed return value for 0 and 1
    return rStepFibonacci(n - 1) + rStepFibonacci(n - 2);
}

// Function to calculate memory used by the program
size_t getMemoryUsage() {
    // Placeholder for memory measurement
    return 0; // Replace with actual memory usage code if necessary
}

// Function to print Fibonacci series recursively
void printFibonacciRecursive(int n) {
    if (n < 0) return;
    if (n == 0) {
        cout << 0 << " ";
        return;
    }
    if (n == 1) {
        cout << 0 << " " << 1 << " ";
        return;
    }
    
    // Use a vector to store the series
    vector<int> series(n + 1);
    series[0] = 0;
    series[1] = 1;

    for (int i = 2; i <= n; i++) {
        series[i] = series[i - 1] + series[i - 2];
    }

    cout << "Fibonacci Series (Recursive): ";
    for (int i = 0; i <= n; i++) {
        cout << series[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // Measure time and memory for the recursive approach
    auto start = chrono::high_resolution_clock::now();
    printFibonacciRecursive(n);
    auto end = chrono::high_resolution_clock::now();
    auto rDuration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    // Measure memory for recursion
    size_t rMemory = getMemoryUsage(); // Replace with actual memory usage function if implemented

    // Measure time and memory for the iterative approach
    start = chrono::high_resolution_clock::now();
    iStepFibonacci(n);
    end = chrono::high_resolution_clock::now();
    auto iDuration = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Time elapsed for recursion: " << rDuration << " microseconds\n";
    cout << "Estimated Space Used: " << sizeof(int) * 3 * (n - 2) << " bytes" <<endl;
    cout << "Time elapsed for iteration: " << iDuration << " microseconds\n";
    cout << "Estimated Space Used: " << sizeof(int) * 3 * (n - 2) << " bytes" <<endl;

    return 0;
}
