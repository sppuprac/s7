#include <iostream>
#include <vector>
using namespace std;

// Recursive function to calculate Fibonacci sequence
vector<int> fibonacci_recursive(int n) {
    if (n <= 0) return {};
    if (n == 1) return {0};
    if (n == 2) return {0, 1};
    vector<int> seq = fibonacci_recursive(n - 1);
    seq.push_back(seq[seq.size() - 1] + seq[seq.size() - 2]);
    return seq;
}

// Iterative function to calculate Fibonacci sequence
vector<int> fibonacci_iterative(int n) {
    if (n <= 0) return {};
    vector<int> seq = {0};
    if (n > 1) seq.push_back(1);
    for (int i = 2; i < n; ++i) {
        seq.push_back(seq[i - 1] + seq[i - 2]);
    }
    return seq;
}

int main() {
    int n;
    cout << "Enter the number of Fibonacci terms to print: ";
    cin >> n;

    string method;
    cout << "Choose method (recursive/iterative): ";
    cin >> method;

    vector<int> result;
    if (method == "recursive") {
        result = fibonacci_recursive(n);
    } else if (method == "iterative") {
        result = fibonacci_iterative(n);
    } else {
        cout << "Invalid method chosen. Please choose either 'recursive' or 'iterative'." << endl;
        return 1;
    }

    cout << "Fibonacci sequence up to " << n << " terms: ";
    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}
