#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

// starts encoding sequentially from 256
vector<int> encoding(string s1) {
    cout << "Encoding\n";
    // table for storing codes (can be stored by a server to simplify decoding)
    unordered_map<string, int> table;

    // adding each individual characters code to encoding table
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[ch] = i;
    }
 
    string prev = "";
    string curr = "";
    prev += s1[0];
    int code = 256;

    vector<int> output_code;
    cout << "String\tOutput_Code\tAddition\n";

    for (int i = 0; i < s1.length(); i++) {
        // if not last encoding curr goes ahead
        if (i != s1.length() - 1) {
            curr += s1[i + 1];
        }  

        // if encoding exists set string which is stored to reflect it
        if (table.find(prev + curr) != table.end()) {
            prev = prev + curr;
        }
        else {
            cout << prev << "\t" << table[prev] << "\t\t"
                 << prev + curr << "\t" << code << endl;
            output_code.push_back(table[prev]);
            table[prev + curr] = code;
            code++;
            prev = curr;
        }

        // needed for ease of string operations and to reset our current encoding outlook
        curr = "";
    }

    // clean up for last encoding (no curr)
    cout << prev << "\t" << table[prev] << endl;
    output_code.push_back(table[prev]);
    
    return output_code;
}

// this decoding only works assuming UNIX standard ascii storage and encoding stores in a sequential manner from 256 onwards
void decoding(vector<int> op) {
    cout << "\nDecoding\n";
    
    unordered_map<int, string> table;
    for (int i = 0; i <= 255; i++) {
        string ch = "";
        ch += char(i);
        table[i] = ch;
    }

    int n;
    int old = op[0];
    string s = table[old];
    string c = "";
    c += s[0];
    cout << s;
    int count = 256;
    for (int i = 0; i < op.size() - 1; i++) {
        n = op[i + 1];
        if (table.find(n) == table.end()) {
            s = table[old];
            s = s + c;
        }
        else {
            s = table[n];
        }
        cout << s;
        c = "";
        c += s[0];
        table[count] = table[old] + c;
        count++;
        old = n;
    }
}


// DRIVER CODE for LZW compression
// Can be altered to have a storing table(usually 4096 char*) so decoding can be as simple as accessing code location
int main (int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Problem with input for compression!" << std::endl;
        return 0;
    }

    std::string data(argv[1]);

    cout << endl;
    vector<int> output_code = encoding(data);
    cout << "Output Codes are: ";
    for (int i = 0; i < output_code.size(); i++) {
        cout << output_code[i] << " ";
    }
    cout << endl;
    decoding(output_code);
    cout << endl << endl;

    return 0;
}