/* https://adventofcode.com/2024/day/6 */ 

#include "load_input_utils.h"

struct Solution {
    int direction = 0;
    bool isInsideMap = true;
    std::pair<int, int> currentLocation;
    bool directionChanged = false;

    enum Directions {
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    double taskOne(std::vector<std::vector<char>>& input) {
        // find the starting point
        double answer = 0;
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
        
        answer = recursiveSearch(input, r+1, c, answer);

        return answer;
    }
    
    double recursiveSearch(std::vector<std::vector<char>>& input, int r, int c, int result) {
        // from starting point, recursivly move up
        if (r < 0 || c < 0 || size_t(r) >= input.size() || size_t(c) >= input[r].size()) {
            // we're out of bounds. Guard exits map here.
            isInsideMap = false;
            return 0;
        }
        if (input[r][c] == '#') {
            // we encountered obstacle. Change direction
            direction = direction == 3 ? 0 : direction + 1;

            // change back to position before obstacle
            r = currentLocation.first;
            c = currentLocation.second;

            return 0;
        }

        result++;
        
        currentLocation = { r,c };
        if (direction == UP && isInsideMap) {
            r--;
            result += recursiveSearch(input, r, c, result);
        }
        if (direction == RIGHT && isInsideMap) {
            c++;
            result += recursiveSearch(input, r, c, result);
        }
        if (direction == DOWN && isInsideMap) {
            r++;
            result += recursiveSearch(input, r, c, result);
        }
        if (direction == LEFT && isInsideMap) {
            c--;
            result += recursiveSearch(input, r, c, result);
        }
        
        return result;
    }
    //double taskTwo() {

    //}
};

int main(int argc, char* argv[]) {
    Input* data = new Input();
    Solution* solution = new Solution();

    std::vector<std::vector<char>>* input_1;

    std::string fileName = "input.txt";

    int answer = 0;
////////////////////////////////////////

    input_1 = data->loadInput(fileName);
    data->printInput(*input_1);

    std::cout << std::setprecision(0) << std::fixed << std::endl;

    answer = solution->taskOne(*input_1);
    std::cout << "We calculate the answer to Day 6, Task 1 to be: " << answer << std::endl;
    std::cin.get();

    return 0;
}
