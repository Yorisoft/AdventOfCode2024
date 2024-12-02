#include<iostream>
#include<vector>
#include<sstream>
#include<string>
#include<fstream>

class Input {
private:
	std::vector<std::vector<int>>* input;
	std::ifstream inputFile;

public:
	Input();
	std::vector<std::vector<int>>* getInput(std::string&);
	void printInput(std::vector<std::vector<int>>* input);
	~Input();
};

Input::Input() {
	input = new std::vector<std::vector<int>>();
}

Input::~Input() {
	delete input;
}

std::vector<std::vector<int>>* Input::getInput(std::string& file_name) {
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
		iss.clear();
		iss.str(line);
	
		std::vector<int> level;
		int value;
		while (iss >> value) {
			level.push_back(value);
		}
		this->input->push_back(level);
	}
	return this->input;
}

void Input::printInput(std::vector<std::vector<int>>* input) {
	for (auto& row : (*input)) {
		for (int col : row) {
			std::cout << col << " | ";
		}
		std::cout << std::endl;
	}
}