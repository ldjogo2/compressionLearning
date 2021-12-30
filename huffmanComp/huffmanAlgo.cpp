#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

// A Huffman tree node
struct MinHeapNode {
  
    // One of the input characters
    char data;
  
    // Frequency of the character
    unsigned freq;
  
    // Left and right child
    MinHeapNode *left, *right;
  
    MinHeapNode(char data, unsigned freq)
  
    {
  
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
  
// For comparison of
// two heap nodes (needed in min heap)
struct compare {
  
    bool operator()(MinHeapNode* l, MinHeapNode* r)
  
    {
        return (l->freq > r->freq);
    }
};
  
// Prints huffman codes from
// the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str)
{
  
    if (!root)
        return;
  
    if (root->data != '$')
        std::cout << root->data << ": " << str << "\n";
  
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
  

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(std::vector<char> data, std::vector<int> freq, int size)
{
    struct MinHeapNode *left, *right, *top;
  
    // Create a min heap & inserts all characters of data[]
    std::priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
  
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
  
    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
  
        // Extract the two minimum
        // freq items from min heap
        left = minHeap.top();
        minHeap.pop();
  
        right = minHeap.top();
        minHeap.pop();
  
        // Create a new internal node with
        // frequency equal to the sum of the
        // two nodes frequencies. Make the
        // two extracted node as left and right children
        // of this new node. Add this node
        // to the min heap '$' is a special value
        // for internal nodes, not used
        top = new MinHeapNode('$', left->freq + right->freq);
  
        top->left = left;
        top->right = right;
  
        minHeap.push(top);
    }
  
    // Print Huffman codes using
    // the Huffman tree built above
    printCodes(minHeap.top(), "");
}
  

// DRIVER CODE FOR STRING PASSED IN
// CHANGE THIS IF YOU ARE PASSING IN DATA SOME OTHER WAY THROUGH CLI
int main (int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Problem with input for compression!" << std::endl;
        return 0;
    }

    std::string data(argv[1]);

    // getting frequency of each character
    std::unordered_map<char, int> ch;
    for (char c : data) {
        if (ch.find(c) != ch.end()) {
            ch[c]++;
        }
        else {
            ch[c] = 1;
        }
    }

    // putting each character and associated freq in vector
    std::vector<char> characters;
    std::vector<int> freq;

    for (auto pair : ch) {
        characters.push_back(pair.first);
        freq.push_back(pair.second);
    }
    std::cout << "Character Encodings" << std::endl;
    HuffmanCodes(characters, freq, characters.size());

    std::cout << "\n\n\nCharacters : Frequencies" << std::endl;
    for (int i = 0; i < characters.size(); i++) {
        std::cout << characters[i] << " : " << freq[i] << std::endl;
    }

    return 0;
}