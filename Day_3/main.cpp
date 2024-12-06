#include<iostream>
#include "load_input_utils.cpp"
#include<regex>
#include<iomanip>

double taskOne(std::vector<std::string>*);
double taskTwo(std::vector<std::string>*);

int main() {

	std::vector<std::string>* input;
	Input *data = new Input();

	std::string fileName = "input.txt";
	input = data->getInput(fileName);
	data->printInput(input);
	std::cin.get();

	double answer = taskOne(input); 
	std::cout << std::fixed << std::setprecision(0);
	std::cout << "We calculate the answer for Day 3, Task 1 to be: " << answer << std::endl;
	std::cin.get();
	
	answer = taskTwo(input);
	std::cout << std::fixed << std::setprecision(0);
	std::cout << "We calculate the answer for Day 3, Task 2 to be: " << answer << std::endl;
	std::cin.get();

	return 0;
}
double taskOne(std::vector<std::string>* input) {

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

			answer += (num1 * num2);
		}
	}
	return answer;
}

double taskTwo(std::vector<std::string>* input) {

	// ------------------------------- TASK 2 --------------------------------- //
	// This task kicked my butt for 3 days straight..
	// To be fair it was in major part due to missundestanding of the task.
	// Things I didnt know up to this point: 
	// The input is 1 big string, not 6 seperate strings.
	// The program doesnt reset to enables at the start of every string/input ( cause its only 1 string/input )
	// All instances of do or don't count, not just most recent. Not sure what instructions meant by that. 
	// 
	// So.. Solution
	// Same as task 1, 
	// set mode to true, pos to 0
	// create new string newInput
	// find all matching instances of the pattern do() or don't()
	// For each instance, if mode is true add that substring from pos to match.position to newInput
	// update mode to true if match is do(), update it to false if match is don't()
	// update position. end for loop
	// if pos is not to the end of string, and mode is true that means no other instructions where found 
	// add remainder of string to newInput
	std::regex pattern(R"(do\(\)|don't\(\))");
	std::vector<std::string> newInput;
	bool mode = true;

	for (std::string line : *input) {
		std::sregex_iterator rit = std::sregex_iterator(line.begin(), line.end(), pattern);
		std::sregex_iterator ritEnd = std::sregex_iterator();
		
		size_t pos = 0;
		std::string cleanSubStr;

		for (auto i = rit; i != ritEnd; i++) {
			if (mode) {
				cleanSubStr += line.substr(pos, i->position() - pos);
			}

			if (i->str() == "do()") {
				mode = true;
			}
			else if (i->str() == "don't()"){
				mode = false;
			}
			pos = i->position() + i->length();
		}
		if( pos < line.size() && mode) {
			// If no instructions were found
			// or "do()" was the last instrution
			// AND we have not reached the end of current substring
			// add the current substring
			cleanSubStr += line.substr(pos);

		}	
		std::cout << "Original: " << std::endl << line << std::endl;
		std::cout << "Cleaned : " << std::endl << cleanSubStr << std::endl;
		newInput.push_back(cleanSubStr);
	} 

	return taskOne(&newInput);
}
