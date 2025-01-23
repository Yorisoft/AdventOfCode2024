#include<iostream>
#include<vector>
#include<utility>
#include<sstream>
#include<string>
#include<fstream>

class Input {
private:
	std::vector<std::pair<int,int>>* input_1;
	std::vector<std::vector<int>>* input_2;

public:
	Input();
	std::vector<std::pair<int,int>>* getInput_1(std::string&);
	std::vector<std::vector<int>>* getInput_2(std::string&);
	void printInput(std::vector<std::pair<int,int>>* input);
	void printInput(std::vector<std::vector<int>>* input);
	~Input();
};

Input::Input() {
	input_1 = new std::vector<std::pair<int,int>>();
	input_2 = new std::vector<std::vector<int>>();
}

Input::~Input() {
	delete input_1;
	delete input_2;
}

std::vector<std::pair<int,int>>* Input::getInput_1(std::string& file_name) {
	std::string line;
	std::ifstream inputFile;

	inputFile.open(file_name);
	while (inputFile.fail()) {
		std::cout << "Could not open file for input 1: " << file_name << std::endl
			<< "Please provide another file name or path" << std::endl;

		std::cin >> std::ws;
		std::getline(std::cin, file_name);

		inputFile.clear(); 
		inputFile.open(file_name);
	}
	std::cout << "Opened file: " << file_name << std::endl;

    while (std::getline(inputFile, line)) {
        std::istringstream iss;
        std::pair<int,int> myPair;
        iss.str(line);
        std::string value;
        std::vector<int> currentInputLine;

        // original 
        //char delimeter;
        //while (iss >> myPair.first >> delimeter >> myPair.second) {
        //	(*input_1).push_back(myPair);
        //}

        try {
            //improved
            std::getline(iss, value, '|');
            myPair.first = std::stoi(value);
            std::getline(iss, value);
            myPair.second = std::stoi(value);
            (*input_1).push_back(myPair);
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input: " << value << std::endl;
			continue;
        }
	}
	inputFile.close();
	return input_1;
}

std::vector<std::vector<int>>* Input::getInput_2(std::string& file_name) {
	std::string line;
	std::ifstream inputFile;

	inputFile.open(file_name);
	while (inputFile.fail()) {
		std::cout << "Could not open file for input 2: " << file_name << std::endl
			<< "Please provide another file name or path" << std::endl;

		std::cin >> std::ws;
		std::getline(std::cin, file_name);

		inputFile.clear(); 
		inputFile.open(file_name);
	}
	std::cout << "Opened file: " << file_name << std::endl;

	while (std::getline(inputFile, line)) {
		std::istringstream iss;
		iss.str(line);
		std::string value;
		std::vector<int> currentInputLine;
	
		try {
            while (std::getline(iss, value, ',')) {
                currentInputLine.push_back(std::stoi(value));
            }
			(*input_2).push_back(currentInputLine);
		}
		catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input: " << value << std::endl;
			continue;
		}
	}
	inputFile.close();
	return input_2;
}

void Input::printInput(std::vector<std::vector<int>>* input) {
	for (std::vector<int> line : *input) {
		for (int i : line) {
			std::cout << i << ',';
		}
		std::cout << std::endl;
	}
}

void Input::printInput(std::vector<std::pair<int,int>>* input) {
	for (auto& pair : *input) {
		std::cout << pair.first << '|' << pair.second << std::endl;
	}
}