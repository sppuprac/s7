#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    double ratio;
    Item(int v, int w) : value(v), weight(w), ratio((double)v / w) {}
};

bool compare(const Item& a, const Item& b) {
    return a.ratio > b.ratio;  // Sort in descending order of value-to-weight ratio
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);
    double totalValue = 0;
    for (auto& item : items) {
        if (capacity <= 0) break;
        int wt = min(item.weight, capacity);
        totalValue += wt * item.ratio;
        capacity -= wt;
    }
    return totalValue;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items and knapsack capacity: ";
    cin >> n >> capacity;
    
    vector<Item> items(n);
    for (int i = 0, v, w; i < n; ++i) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> v >> w;
        items[i] = Item(v, w);
    }

    cout << "Maximum value in the knapsack: " << fractionalKnapsack(capacity, items) << endl;
    return 0;
}
