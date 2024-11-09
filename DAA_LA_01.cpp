#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void printFibonacci(int n) {
    static int n1 = 0, n2 = 1, n3;

    if (n > 0) {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        cout << n3 << " ";
        printFibonacci(n - 1);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Fibonacci Series: ";
    cout << "0 " << "1 ";

    auto start_time = high_resolution_clock::now();

    printFibonacci(n - 2);

    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    cout << "\nElapsed Time: " << duration.count() << " microseconds" << endl;

    cout << "Estimated Space Used: " << sizeof(int) * 3 * (n - 2) << " bytes" << endl;

    return 0;
}

// Using Non recursion:

#include <iostream>

using namespace std;

int main() {
    int n1 = 0, n2 = 1, n3, i, number;
    cout << "Enter the number of elements: ";

    cin >> number;
    cout << n1 << " " << n2 << " "; 

    for (i = 2; i < number; ++i) 
    {
        n3 = n1 + n2;
        cout << n3 << " ";
        n1 = n2;
        n2 = n3;
    }

    return 0;
}
