#include <iostream>
#include <string>

using namespace std;

int main (int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Problem with input for compression!" << std::endl;
        return 0;
    }

    std::string data(argv[1]);
    for (auto c : data) {
        std::cout << c << std::endl;
    }

    return 0;
}