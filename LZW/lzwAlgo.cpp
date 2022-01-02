#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

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
 
    string p = "";
    string c = "";
    p += s1[0];
    int code = 256;
    vector<int> output_code;
    cout << "String\tOutput_Code\tAddition\n";

    for (int i = 0; i < s1.length(); i++) {
        if (i != s1.length() - 1) {
            c += s1[i + 1];
        }

        if (table.find(p + c) != table.end()) {
            p = p + c;
        }
        else {
            cout << p << "\t" << table[p] << "\t\t"
                 << p + c << "\t" << code << endl;
            output_code.push_back(table[p]);
            table[p + c] = code;
            code++;
            p = c;
        }

        c = "";
    }
    // clean up for last character
    cout << p << "\t" << table[p] << endl;
    output_code.push_back(table[p]);
    
    return output_code;
}


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