#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<map>


int calculateDiffSum(std::vector<int>&, std::vector<int>& );
void selectionSort(std::vector<int>&);
void openInputFile(std::ifstream&, std::string&);
void printLists(std::vector<int>&, std::vector<int>&);

int main() {
//------------------------------------------- Part 1 -----------------------------------------------//
	// open input from file
	std::ifstream inputFile;
	std::string fileName = "input.txt";
	openInputFile(inputFile, fileName);

	// load data from input file. line by line
	std::string line;
	std::vector<int>left_list;
	std::vector<int>right_list;

	while (std::getline(inputFile, line)) {
		std::istringstream iss(line);
		int left, right;

		if (iss >> left >> std::ws >> right) {
			left_list.push_back(left);
			right_list.push_back(right);
		}
	}

	inputFile.close();

	std::cout << "finished loading data into vectors: left_list, right_list" << std::endl;
	printLists(left_list, right_list);

	// sort lists
	selectionSort(left_list);
	selectionSort(right_list);

	std::cout << "Lists have been sorted :) " << std::endl;	
	printLists(left_list, right_list);

	// calculate the sum of differences
	int answer = calculateDiffSum(left_list, right_list);
	std::cout << "We calculate the answer to task 1 to be: " << answer << std::endl;


//------------------------------------------- Part 2 -----------------------------------------------//
	// Task 2!!
	// for each element in right_list,
	// add it to the map and increase its value +1
	// key = list[i], value = accurance
	// for each element in left_list
	// if it exist on the map
	// find it on the map and get its occurance, 
	// multiple these two value and add to similarity score

	std::map<int, int> occurrence_map;

	for (int number : right_list) {
		occurrence_map[number]++;
	}
	// print results thus far.	
	for (auto& pair : occurrence_map) {
		std::cout << "Number: " << pair.first << " , Occurrences: " << pair.second << std::endl;
	}
	std::cin.get();

	float similarity_score = 0;
	for (int number : left_list) {
		if (occurrence_map.find(number) != occurrence_map.end()) {
			similarity_score += (occurrence_map[number] * number);
		}
	}
	std::cout << "We calculate the answer to task 2 to be: " << std::fixed << similarity_score << std::endl;

	std::cin.get();
	return 0;
}

void openInputFile(std::ifstream& inputFile, std::string& fileName) {
	inputFile.open(fileName);

	while (inputFile.fail()) {
		std::cout << "Could not open file: " << fileName << std::endl
			<< "Please provide path or filename" << std::endl;
		
		std::cin >> std::ws;
		std::getline(std::cin, fileName);
		inputFile.open(fileName);
	}

	std::cout << "Opened file: " << fileName << std::endl;
}

void printLists(std::vector<int>& left_list, std::vector<int>& right_list) {
	for (int i = 0; i < left_list.size(); i++) {
		std::cout << left_list[i] << "    " << right_list[i] << std::endl;
	}
}

void selectionSort(std::vector<int>& list) {
	for (int i = 0; i < list.size() - 1; i++) { 
		int minValue = list[i],
		minIndex = i;
		for (int j = i+1; j < list.size(); j++) {
			if (list[j] < minValue) {
				minValue = list[j];
				minIndex = j;
			}
		}
		int temp = list[i];
		list[i] = minValue;
		list[minIndex] = temp;
	}
}


int calculateDiffSum(std::vector<int>& left_list, std::vector<int>& right_list) {
	int sum = 0;
	for (int i = 0; i < left_list.size(); ++i) {
		int diff = std::abs(right_list[i] - left_list[i]);
		sum += diff;
	}
	return sum;
}
