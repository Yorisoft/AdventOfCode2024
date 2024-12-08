#include "load_input_utils.cc"

class Solution {
private:

public:
    Solution() {};
    ~Solution() {};
};

int main(int argc, char* argv[]) {
    std::vector<std::pair<int, int>>* input_1;
    std::vector<std::vector<int>>* input_2;
    Input* data = new Input();

    std::string
        fileName_1 = "input_1.txt",
        fileName_2 = "input_2.txt";

    input_1 = data->getInput_1(fileName_1);
    input_2 = data->getInput_2(fileName_2);


    data->printInput(input_1);
    data->printInput(input_2);

    return 0;
}