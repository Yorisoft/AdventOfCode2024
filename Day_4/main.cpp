#include "load_input_utils.cpp"
#include <set>
#include <utility>
#include <iomanip>

class Solution {
private: 	
    std::string xmass_pattern = "XMAS";
	std::vector<std::pair<int, int>> xmass_directions = {
		{-1, 0},	// up
		{1, 0},		// down
		{0, -1},	// left
		{0, 1},		// right
		{-1, -1},	// up-left
		{-1, 1},	// up-right
		{1, -1},	// down-left
		{1, 1},		// down-right
	};

	double circleSearch(std::vector<std::vector<char>>* input, int r, int c, int index, int dr, int dc) {
		if (r >= (*input).size() || c >= (*input)[0].size() || r < 0 || c < 0) // if true, we're out of bounds 
			return 0;
		if ((*input)[r][c] != xmass_pattern[index]) // the current index in input does not match the current index in pattern, missmatch
			return 0;
		if (index == xmass_pattern.size() - 1) // index is equal to pattern.size() - 1, meaning we've gotten to the end without missmatch.
			return 1;

		return circleSearch(input, r + dr, c + dc, index + 1, dr, dc);
	}

	double xSearch(std::vector<std::vector<char>>* input, int r, int c) {
		if (r + 1 >= (*input).size() || c + 1 >= (*input)[0].size() || r - 1 < 0 || c - 1 < 0) // if true, we cannot create an X pattern from 'A' 
			return 0;
		
		// we pass the checks for out of bounds and we found an 'A'
		// Check if the A is surrounded by 'S' and 'M' in an X pattern and in a way that spells MAS
		char up_left = (*input)[r - 1][c - 1];
		char up_right = (*input)[r - 1][c + 1];
		char down_left = (*input)[r + 1][c - 1];
		char down_right = (*input)[r + 1][c + 1];
		//first check if its sourrounded by S or M on the sides that matter, X pattern
		// Check for MAS patterns in diagonals

		// this doesnt work??? 
		if ((up_left == 'M' && down_right == 'S' || up_left == 'S' && down_right == 'M') &&
			(up_right == 'M' && down_left == 'S' || up_right == 'S' && down_left == 'M')) {
			return 1;
		} 
		return 0;
	}

public:
	Solution() {}
	~Solution() {}

	double taskOne(std::vector<std::vector<char>>* input) {
		double answer = 0;
		for (int r = 0; r < input->size(); r++) {
			for (int c = 0; c < (*input)[0].size(); c++) {
				// search in all directions for each element. BUT maintain the direction per search.
				for (std::pair<int, int> direction : xmass_directions) {
					answer += circleSearch(input, r, c, 0, direction.first, direction.second);
				}
			}
		}
		return answer;
	}

	double taskTwo(std::vector<std::vector<char>>* input) {
		double answer = 0;
		for (int r = 0; r < input->size(); r++) {
			for (int c = 0; c < (*input)[0].size(); c++) {
				// If the current cell is A, search in an X pattern for the raimain char..
				if((*input)[r][c] == 'A'){
					answer += xSearch(input, r, c);
				}
			}
		}
		return answer;
	}
};

int main(int argc, char* argv[]) {
	std::vector<std::vector<char>>* input;
	std::string file_name = "input.txt";
	
	Input* data = new Input();	
	input = data->getInput(file_name);
	data->printInput(input);
	
	Solution* solution = new Solution();
	double answer = solution->taskOne(input);

	std::cout << std::fixed << std::setprecision(0);
	std::cout << "We calculate the answer to Day 4, Task 1 to be: " << answer << std::endl;
	std::cin.get();

	answer = solution->taskTwo(input);
	std::cout << std::fixed << std::setprecision(0);
	std::cout << "We calculate the answer to Day 4, Task 2 to be: " << answer << std::endl;
	std::cin.get();
}

