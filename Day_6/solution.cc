/* https://adventofcode.com/2024/day/6 */ 

#include "load_input_utils.h"

struct Solution {
    int direction = 0;
    enum Directions {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    double taskOne(std::vector<std::vector<char>>& input) {
        int r, c;

        for (size_t i = 0; i < input.size(); i++) {
            bool found = false;

            for (size_t j = 0; j < input[i].size(); j++) {
                if (input[i][j] == '^') {
                    r = i, c = j;
                    found = true;
                    break;
                }
            }
            if (found)
                break;
        }
        std::cout << "Starting point position is: input[" << r << "][" << c << "]\n";

        // calculate answer
        // r+1 to skip starting position
        return rightTurnSearch(input, r+1, c);
    }
    
    double rightTurnSearch(std::vector<std::vector<char>>& input, int r, int c) {
        std::set<std::pair<int, int>> visited;
        std::pair<int, int> currentLocation;

        while (true) {
            if (r < 0 || c < 0 || size_t(r) >= input.size() || size_t(c) >= input[r].size()) {
                break;
            }
            if (input[r][c] == '#') {
                direction = direction == 3 ? 0 : direction + 1;

                r = currentLocation.first;
                c = currentLocation.second;

                continue;
            }
            else {
                visited.insert({ r,c });
                
                currentLocation = { r,c };
                switch (direction) {
                    case UP:    r--; break;
                    case RIGHT: c++; break;
                    case DOWN:  r++; break;
                    case LEFT:  c--; break;
                }
            }
        }
        return visited.size();
    }

    //double taskTwo() {

    //}
};

int main(int argc, char* argv[]) {
    Input* data = new Input();
    Solution* solution = new Solution();

    std::vector<std::vector<char>>* input_1;

    std::string fileName = "input.txt";


    input_1 = data->loadInput(fileName);
    data->printInput(*input_1);

    std::cout << std::setprecision(0) << std::fixed << std::endl;

    int answer;
    answer = solution->taskOne(*input_1);
    std::cout << "We calculate the answer to Day 6, Task 1 to be: " << answer << std::endl;
    std::cin.get();

    delete data;
    data = nullptr;
    delete solution;
    solution = nullptr;
   
    // input pointer is handled by data object.
    input_1 = nullptr;

    return 0;
}
