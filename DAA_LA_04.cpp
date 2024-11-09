#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Item {
    int weight;
    int value;
};

int knapsack_bb(vector<Item>& items, int W, int n) {
    // Base case
    if (n == 0 || W == 0) {
        return 0;
    }

    // If the weight of the current item is more than the knapsack capacity,
    // then this item cannot be included in the optimal solution
    if (items[n - 1].weight > W) {
        return knapsack_bb(items, W, n - 1);
    }

    // Recursively compute the maximum value by including or excluding the current item
    int include = items[n - 1].value + knapsack_bb(items, W - items[n - 1].weight, n - 1);
    int exclude = knapsack_bb(items, W, n - 1);

    return max(include, exclude);
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    cout << "Enter the values and weights for each item (value weight):\n";
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    int max_value = knapsack_bb(items, W, n);
    cout << "Maximum value: " << max_value << endl;

    return 0;
}
