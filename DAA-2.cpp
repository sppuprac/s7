#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* l, Node* r) { return l->freq > r->freq; }
};

Node* buildHuffmanTree(const unordered_map<char, int>& freq) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    for (auto& p : freq) minHeap.push(new Node(p.first, p.second));
    while (minHeap.size() > 1) {
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();
        Node *merged = new Node('\0', left->freq + right->freq);
        merged->left = left; merged->right = right;
        minHeap.push(merged);
    }
    return minHeap.top();
}

void generateCodes(Node* root, const string& str, unordered_map<char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) codes[root->ch] = str;
    generateCodes(root->left, str + "0", codes);
    generateCodes(root->right, str + "1", codes);
}

pair<string, unordered_map<char, string>> huffmanEncoding(const string& text) {
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;
    unordered_map<char, string> codes;
    generateCodes(buildHuffmanTree(freq), "", codes);
    string encoded;
    for (char ch : text) encoded += codes[ch];
    return {encoded, codes};
}

string huffmanDecoding(const string& encoded, const unordered_map<char, string>& codes) {
    unordered_map<string, char> reverseCodes;
    for (auto& p : codes) reverseCodes[p.second] = p.first;
    string decoded, current;
    for (char bit : encoded) {
        current += bit;
        if (reverseCodes.count(current)) {
            decoded += reverseCodes[current];
            current.clear();
        }
    }
    return decoded;
}

int main() {
    string text = "hello huffman";
    cout << "Original text: " << text << endl;

    auto result = huffmanEncoding(text);
    string encodedText = result.first;
    unordered_map<char, string> huffmanCodes = result.second;

    cout << "Encoded text: " << encodedText << endl;
    cout << "Huffman Codes:\n";
    for (auto& p : huffmanCodes) cout << p.first << ": " << p.second << endl;

    cout << "Decoded text: " << huffmanDecoding(encodedText, huffmanCodes) << endl;
    return 0;
}

