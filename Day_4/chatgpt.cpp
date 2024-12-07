#include "load_input_utils.cpp"
#include <set>
#include <utility>
#include <iomanip>

// Including the ChatGPT solution untill I'm able to solve why my solution doesnt work.

class Solution {
private:
	std::string pattern = "XMAS";
	// Directions as row, column shifts (up, down, left, right, etc.)
	std::vector<std::pair<int, int>> directions = {
		{-1, -1}, // up/left
		{-1, 0},  // up
		{-1, 1},  // up/right
		{0, -1},  // left
		{0, 1},   // right
		{1, -1},  // down/left
		{1, 0},   // down
		{1, 1}    // down/right
	};
	bool dfs(std::vector<std::vector<char>>* input, int r, int c, int dr, int dc) {

		// ChatGPT code.. 
		// during the first itteration i, r, and c = 0 so when multipled it will be 0. after the first iteration
		/// it moves in one direction. 
		// why does this work but my code doesnt?  
		for (int i = 0; i < pattern.size(); ++i) {
			int nr = r + i * dr; // next row
			int nc = c + i * dc; // next column
			if (nr < 0 || nr >= input->size() || nc < 0 || nc >= (*input)[0].size() || (*input)[nr][nc] != pattern[i]) {
				return false; // Out of bounds or mismatch
			}
		}
		return true;

	}

public:
	Solution() {}
	~Solution() {}

	double taskOne(std::vector<std::vector<char>>* input) {
		double answer = 0;
		for (int r = 0; r < input->size(); r++) {
			for (int c = 0; c < (*input)[0].size(); c++) {
				// search in all directions for each element. BUT maintain the direction per search.
				for (const auto& direction : directions) {
					if (dfs(input, r, c, direction.first, direction.second)) {
						++answer;
					}
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
}

