#include "load_input_utils.h"


Input::Input() {
    input_1 = new std::vector<std::vector<char>>();
}

Input::~Input() {

}

std::vector<std::vector<char>>* Input::loadInput(std::string& s) {
    std::ifstream inputFile;
    inputFile.open(s);

    while (inputFile.fail()) {
        std::cout << "Failed to open file: " << s << std::endl
            << "Try again." << std::endl
            << "What's the name of the input file? " << std::endl;

        s.clear();
        std::cin >> std::ws;
        std::getline(std::cin, s);

        inputFile.clear();
        inputFile.open(s);
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::vector<char> tempLine;

        try {
            for (char& c : line) {
                tempLine.push_back(c);
            }
            input_1->push_back(tempLine);
        }
        catch (const std::invalid_argument& e){
            std::cerr << e.what() << std::endl;
            continue;
        }
    }

    return input_1;
}

void Input::printInput(std::vector<std::vector<char>>& input) const {
    for (std::vector<char>& r : input) {
        for (char c : r) {
            std::cout << c;
       }
        std::cout << std::endl;
    }
}
