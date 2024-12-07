//#include "load_input_utils.cpp"
//#include <set>
//#include <utility>
//#include <iomanip>
//
//class Solution {
//private: 	
//    std::string pattern = "XMAS";
//	std::vector<std::string> directions = {
//		"up/left", "up", "up/right",
//		"left", "right",
//		"down/left", "down", "down/right"
//	};
//
//	double dfs(std::vector<std::vector<char>>* input, int r, int c, int index, std::string direction) {
//		if (index == pattern.size() - 1) // index is equal to last index of pattern, meaning we've gotten to the end without missmatch.
//			return 1;
//		if (r >= (*input).size() || c >= (*input)[0].size() || r < 0 || c < 0) // if true, we're out of bounds 
//			return 0;
//		if ((*input)[r][c] != pattern[index]) // the current index in input does not match the current index in pattern, missmatch
//			return 0;
//
//		double result = 0;
//		if ((*input)[r][c] == pattern[index]){
//			if (direction == "up") {
//				// dfs up
//				result += dfs(input, r - 1, c, index + 1, "up");
//			}
//			// dfs up/right
//			if (direction == "up/right") {
//				result += dfs(input, r - 1, c + 1, index + 1, "up/right");
//			}
//			// dfs right
//			if (direction == "right") {
//				result += dfs(input, r, c + 1, index + 1, "right");
//			}
//			// dfs right/down
//			if (direction == "down/right") {
//				result += dfs(input, r + 1, c + 1, index + 1, "down/right");
//			}
//			// dfs down
//			if (direction == "down") {
//				result += dfs(input, r + 1, c, index + 1, "down");
//			}
//			// dfs down/left
//			if (direction == "down/left") {
//				result += dfs(input, r + 1, c - 1, index + 1, "down/left");
//			}
//			// dfs left
//			if (direction == "left") {
//				result += dfs(input, r, c - 1, index + 1, "left");
//			}
//			// dfs left/up
//			if (direction == "up/left") {
//				result += dfs(input, r - 1, c - 1, index + 1, "up/left");
//			}
//		}	
//		
//		return result;
//	}
//
//public:
//	Solution() {}
//	~Solution() {}
//
//	double taskOne(std::vector<std::vector<char>>* input) {
//		double answer = 0;
//		std::set<std::pair<int, int>> visted_index; 
//		for (int r = 0; r < input->size(); r++) {
//			for (int c = 0; c < (*input)[0].size(); c++) {
//				// search in all directions for each element. BUT maintain the direction per search.
//				for (int i = 0; i < directions.size(); i++) {
//					answer += dfs(input, r, c, 0, directions[i]);
//				}
//			}
//		}
//		return answer;
//	}
//};
//
//int main(int argc, char* argv[]) {
//	std::vector<std::vector<char>>* input;
//	std::string file_name = "input.txt";
//	
//	Input* data = new Input();	
//	input = data->getInput(file_name);
//	data->printInput(input);
//	
//	Solution* solution = new Solution();
//	double answer = solution->taskOne(input);
//
//	std::cout << std::fixed << std::setprecision(0);
//	std::cout << "We calculate the answer to Day 4, Task 1 to be: " << answer << std::endl;
//	std::cin.get();
//}

