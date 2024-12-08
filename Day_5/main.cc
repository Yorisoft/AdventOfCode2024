#include "load_input_utils.cc"
#include<iomanip>

class Solution {
private:

public:
    Solution() {};
    ~Solution() {};

    double taskOne(std::vector<std::pair<int, int>>* input_1, std::vector<std::vector<int>>* input_2) {
        double result = 0;
        for (auto& pages : *input_2) {
            bool isValid = true;
            for (auto& rule : *input_1) {
                std::vector<int>::iterator ruleOne = std::find(pages.begin(), pages.end(), rule.first);
                std::vector<int>::iterator ruleTwo = std::find(pages.begin(), pages.end(), rule.second);
                
                if ((ruleOne != pages.end() && ruleTwo != pages.end()) && !(ruleOne < ruleTwo)) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                result += pages[pages.size()/2];  
            } 
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    std::vector<std::pair<int, int>>* input_1;
    std::vector<std::vector<int>>* input_2;
    Input* data = new Input();
    Solution* solution = new Solution();

    std::string
        fileName_1 = "input_1.txt",
        fileName_2 = "input_2.txt";

    input_1 = data->getInput_1(fileName_1);
    input_2 = data->getInput_2(fileName_2);

    data->printInput(input_1);
    data->printInput(input_2);
    
    int answer = solution->taskOne(input_1, input_2);

    std::cout << std::fixed << std::setprecision(0);
    std::cout << "We calculate the answer to Day 5, Task 1 to be: " << answer << std::endl;
    std::cin.get();

    return 0;
}