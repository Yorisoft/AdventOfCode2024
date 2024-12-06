#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<fstream>

class Input {
private:
	std::vector<std::vector<char>>* input;

public:
	Input();
	std::vector<std::vector<char>>* getInput(std::string&);
	void printInput(std::vector<std::vector<char>>* input);
	~Input();
};

Input::Input() {
	input = new std::vector<std::vector<char>>();
}

Input::~Input() {
	delete input;
}

std::vector<std::vector<char>>* Input::getInput(std::string& file_name) {
	std::istringstream iss;
	std::string line;
	std::ifstream inputFile;

	inputFile.open(file_name);
	while (inputFile.fail()) {
		std::cout << "Could not open file: " << file_name << std::endl
			<< "Please provide another file name or path" << std::endl;

		std::cin >> std::ws;
		std::getline(std::cin, file_name);

		inputFile.open(file_name);
	}
	std::cout << "Opened file: " << file_name << std::endl;

	while (std::getline(inputFile, line)) {
		std::vector<char> currentLine(line.begin(), line.end());
		(*input).push_back(currentLine);
	}
	inputFile.close();
	return input;
}

void Input::printInput(std::vector<std::vector<char>>* input) {
	for (std::vector<char> line : *input) {
		for (char c : line) {
			std::cout << c;
		}
		std::cout << std::endl;
	}
}