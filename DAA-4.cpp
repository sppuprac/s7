#include <bits/stdc++.h>
using namespace std;

int knapsack(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            dp[i][w] = dp[i - 1][w];
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
        }
    }
    return dp[n][capacity];
}

int main() {
    int n, capacity;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> capacity;

    vector<int> values(n), weights(n);
    for (int i = 0; i < n; ++i)
        cin >> values[i] >> weights[i];

    cout << "Maximum value: " << knapsack(weights, values, capacity) << endl;
    return 0;
}
