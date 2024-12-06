#include "load_input_utils.cpp"

int main(int argc, char* argv[]) {
	std::string file_name = "input.txt";
	Input* data = new Input();

	std::vector<std::vector<char>>* input;
	input = data->getInput(file_name);

	data->printInput(input);
}