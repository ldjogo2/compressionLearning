// Credit: Geeks for Geeks Huffman Coding

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

// Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
  
    MinHeapNode *left, *right;
  
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
  
// MinHeap needed
struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};
  
void printCodes(struct MinHeapNode* root, string str)
{
    if (!root)
        return;
  
    if (root->data != '$')  // must be leaf node 
        std::cout << root->data << ": " << str << "\n";
  
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
  

// Main function which builds Huffman Tree and prints codes generated from tree
void HuffmanCodes(std::vector<char> data, std::vector<int> freq, int size)
{
    struct MinHeapNode *left, *right, *top;
    std::priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
  
    while (minHeap.size() != 1) {
        // getting next two minimum values to insert into tree
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
  
        // inserting two min values into tree
        top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
  
        minHeap.push(top);
    }

    // print the codes from the tree
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

        if (c == '$') {
            std::cout << "Cannot include $ as it is used to indicate non-leaf nodes in HuffmanTree!" << std::endl;
            return 0;
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