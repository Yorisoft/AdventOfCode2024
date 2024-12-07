#include "load_input_utils.cpp"
#include <set>
#include <utility>
#include <iomanip>

int dfs(std::vector<std::vector<char>>*, int, int, int, std::string&);
double taskOne(std::vector<std::vector<char>>*);
int main(int argc, char* argv[]) {
	std::vector<std::vector<char>>* input;
	std::string file_name = "input.txt";
	
	Input* data = new Input();	
	input = data->getInput(file_name);
	data->printInput(input);

	double answer = taskOne(input);

	std::cout << std::fixed << std::setprecision(0);
	std::cout << "We calculate the answer to Day 4, Task 1 to be: " << answer << std::endl;
	std::cin.get();

}

double taskOne(std::vector<std::vector<char>>* input) {

	std::string pattern = "XMAS";
	const int
		ROW = input->size(),
		COL = (*input)[0].size();

	double answer = 0;
	std::set<std::pair<int, int>> visted_index; 
	for (int r = 0; r < input->size(); r++) {
		for (int c = 0; c < (*input)[0].size(); c++) {
			answer += dfs(input, r, c, 0, pattern);
		}
	}
	return answer;
}

int dfs(std::vector<std::vector<char>>* input, int r, int c, int index, std::string& pattern) {
	
	if (index == pattern.size() - 1) // index is equal to last index of pattern, meaning we've gotten to the end without missmatch.
		return 1;
	if (r >= (*input).size() || c >= (*input)[0].size() || r < 0 || c < 0) // if true, we're out of bounds 
		return 0;
	if ((*input)[r][c] != pattern[index]) // the current index in input does not match the current index in pattern, missmatch
		return 0;
	//if (visited_index.find({r,c}) != visited_index.end()) { // not sure if I need this.. Might cause errors when seaching in all directions..
	//	return 0;
	//}
	// if our current pos is equal to the size of pattern 
	// AND input[r][c] == the last char in pattern, 
	// we found a match

	int result = 0;
	if ((*input)[r][c] == pattern[index]) {
		// dfs up
		result += dfs(input, r - 1, c, index + 1, pattern);

		// dfs up/right
		 result += dfs(input, r - 1, c + 1, index + 1, pattern);

		// dfs right
		 result += dfs(input, r, c + 1, index + 1, pattern);

		// dfs right/down
		 result += dfs(input, r + 1, c + 1, index + 1, pattern);

		// dfs down
		 result += dfs(input, r + 1, c, index + 1, pattern);

		// dfs down/left
		 result += dfs(input, r + 1, c  - 1, index + 1, pattern);

		// dfs left
		 result += dfs(input, r, c - 1, index + 1, pattern);
		
		// dfs left/up
		 result += dfs(input, r - 1, c - 1, index + 1, pattern);
	}	
	
	return result;
}
