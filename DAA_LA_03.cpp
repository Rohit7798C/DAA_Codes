#include <iostream>
#include <algorithm>
#include <chrono>
#include <iomanip>

using namespace std;
// A struct in C++ is a user-defined data type that groups variables of different data types under a single name.
struct Item {
    int value;
    int weight;
};

class Solution {
public:
    static bool comp(Item a, Item b) {
        double r1 = static_cast<double>(a.value) / static_cast<double>(a.weight);
        double r2 = static_cast<double>(b.value) / static_cast<double>(b.weight);
        return r1 > r2;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr + n, comp);
        int curWeight = 0;
        double finalValue = 0.0;

        for (int i = 0; i < n; i++) {
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalValue += arr[i].value;
            } else {
                int remain = W - curWeight;
                finalValue += (arr[i].value / static_cast<double>(arr[i].weight)) *
                               static_cast<double>(remain);
                break;
            }
        }

        return finalValue;
    }
};

int main() {
    int n = 3, weight = 50;
    Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};
    Solution obj;

    auto start_time = chrono::high_resolution_clock::now();
    double ans = obj.fractionalKnapsack(weight, arr, n);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "The maximum value is " << fixed << setprecision(2) << ans << endl;
    cout << "Elapsed Time: " << duration.count() << " microseconds" << endl;

    return 0;
}

// Optimised code is below

// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;

// struct Item {
//     int value, weight;
// };

// bool cmp(Item a, Item b) {
//     double r1 = (double)a.value / a.weight;
//     double r2 = (double)b.value / b.weight;
//     return r1 > r2;
// }

// double fractionalKnapsack(int W, vector<Item> arr) {
//     sort(arr.begin(), arr.end(), cmp);

//     double finalValue = 0.0;
//     int curWeight = 0;

//     for (Item item : arr) {
//         if (curWeight + item.weight <= W) {
//             curWeight += item.weight;
//             finalValue += item.value;
//         } else {
//             int remain = W - curWeight;
//             finalValue += item.value * ((double)remain / item.weight);
//             break;
//         }
//     }

//     return finalValue;
// }

// int main() {
//     int W = 50;
//     vector<Item> arr = {{100, 20}, {60, 10}, {120, 30}};

//     double maxValue = fractionalKnapsack(W, arr);
//     cout << "Maximum value we can obtain is " << maxValue << endl;

//     return 0;
// }
