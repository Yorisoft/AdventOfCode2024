#include<iostream>
#include "load_input_utils.cpp"

bool isSafe(const std::vector<int>& levels);
bool canBeMadeSafe(const std::vector<int>& levels);

int main() {
	std::vector<std::vector<int>>* input;
	Input* data = new Input();

	// load input
	std::string fileName = "input.txt";
	input = data->getInput(fileName);

	data->printInput(input);

	std::cin.get();

	//------------------------------ TASK 1 --------------------------------- //
	// this one was way trickier than day 1...
	// I was first thinking of using switch case, but that was a noob mistake..
	// Went at it for about 1 hour before asking ChatGPT for help.
	// Easiest way is to divide and conquer this, if at the very least just in your head. 
	// Get a diff between the current element and the next, if it is positive the level is accending if not its decending
	// for each element check that
	// the element prior was also moving in the same direction
	// doesnt increase or decrease by more than 3 but by atleast 1
	// if true ++safeReport, if not move to the next level/c. 
	// return safeReports. 	

	int safeReports = 0; 
	for (const auto& report : *input) { 
		if (isSafe(report)) { 
			++safeReports; 
		} 
	}

	std::cout << "We calculate the answer of Day 2 Task 1 to be: " << safeReports << std::endl; 
	std::cin.get();


	//------------------------------ TASK 2 --------------------------------- //
	// For every element, 
	// create a modified vector without that element and check if its a safe level/vector
	// if can remove one element and it becomes safe, return true,
	// if we go through the vetor and no variation produces a safe level, return false. 
	// check that each level in the report is safe or can be made safe. 


	safeReports = 0; 
	for (const auto& report : *input) { 
		if (isSafe(report) || canBeMadeSafe(report)) { 
			++safeReports; 
		} 
	}

	std::cout << "We calculate the answer of Day 2 Task 2 to be: " << safeReports << std::endl; 
	std::cin.get();

	return 0;
}

// Function to check if a report is safe
bool isSafe(const std::vector<int>& levels) {
	for (size_t i = 0; i < levels.size() - 1; ++i) {
		int diff = levels[i + 1] - levels[i];
		if (std::abs(diff) < 1 || std::abs(diff) > 3) { // If the difference is less than 1 or greater than 3 return false. 
			return false;
		}
		if (i > 0 && (diff > 0) != (levels[i] - levels[i - 1] > 0)) { // if the current difference is not in the same direction as the previous return false 
			return false;
		}
	}
	return true;
}

// Function to check if a report can be made safe 
// for each element, remove it and see if the level is safe without it
// if we can remove an element and make it safe, return true,
// if we go through every modification of the level and none are safe, return false.
bool canBeMadeSafe(const std::vector<int>& levels) {
	for (size_t i = 0; i < levels.size(); ++i) {
		std::vector<int> modifiedLevels = levels;
		modifiedLevels.erase(modifiedLevels.begin() + i);
		if (isSafe(modifiedLevels)) {
			return true;
		}
	}
	return false;
}

