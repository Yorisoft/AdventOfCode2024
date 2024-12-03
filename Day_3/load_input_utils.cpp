#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<fstream>

class Input {
private:
	std::vector<std::string>* input;
	std::ifstream inputFile;

public:
	Input();
	std::vector<std::string>* getInput(std::string&);
	void printInput(std::vector<std::string>* input);
	~Input();
};

Input::Input() {
	input = new std::vector<std::string>();
}

Input::~Input() {
	delete input;
}

std::vector<std::string>* Input::getInput(std::string& file_name) {
	std::istringstream iss;
	std::string line;

	this->inputFile.open(file_name);
	while (this->inputFile.fail()) {
		std::cout << "Could not open file: " << file_name << std::endl
			<< "Please provide another file name or path" << std::endl;

		std::cin >> std::ws;
		std::getline(std::cin, file_name);

		this->inputFile.open(file_name);
	}
	std::cout << "Opened file: " << file_name << std::endl;

	while (std::getline(this->inputFile, line)) {
		(*this->input).push_back(line);
	}
	return this->input;
}

void Input::printInput(std::vector<std::string>* input) {
		for (std::string line : *input) {
			std::cout << line << std::endl << std::endl << std::endl;
		}
		std::cout << std::endl;
}