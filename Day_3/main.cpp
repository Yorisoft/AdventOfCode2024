#include<iostream>
#include "load_input_utils.cpp"
#include<regex>
#include<iomanip>

int main() {

	std::vector<std::string>* input;
	Input *data = new Input();

	std::string fileName = "input.txt";
	input = data->getInput(fileName);
	data->printInput(input);

	std::cin.get();

	// ------------------------------- TASK 1 --------------------------------- //

	// create a regex expression that matches what we're searching for 
	// for each string in input, 
	// search for regex in string and save it in matches
	// for each match 
	// get num1 in mul by skipping the first 4 chars and including everything upto not including ' , '
	// get num2 by skipping 1 after num1 and upto not including ' ) '
	// multiply num1 * num2, save in answer
	// return answer

	std::regex pattern(R"(mul\(\d{1,3},\d{1,3}\))");
	double answer = 0;
	for (std::string line : *input) {
		auto matchStart = std::sregex_iterator(line.begin(), line.end(), pattern);
		auto matchEnd= std::sregex_iterator();
		for (auto i = matchStart; i != matchEnd; i++) {
			std::smatch match = *i;
			std::string match_str = match.str();
			
			std::cout << match_str << std::endl;

			size_t start1 = match_str.find("(") + 1;
			size_t end1 = match_str.find(",");
			size_t start2 = end1 + 1;
			size_t end2 = match_str.find(")");
			
			// more readable
			int num1 = std::stoi(match_str.substr(start1, end1 - start1));
			int num2 = std::stoi(match_str.substr(start2, end2 - start2));

			// if I want code to be short, it would be like this 
			//int num1 = std::stoi(match.substr(4, (match.find(",")) - 4));
			//int num2 = std::stoi(match.substr((match.find(",") + 1), (match.find(")")) - match.find(",") - 1));

			answer += (num1 * num2);

		}
	}

	std::cout << std::fixed << std::setprecision(0);
	std::cout << "We calculate the answer for Day 3, Task 2 to be: " << answer << std::endl;

	std::cin.get();




	// ------------------------------- TASK 2 --------------------------------- //

	return 0;
}