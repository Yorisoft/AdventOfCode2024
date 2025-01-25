#pragma once 
#define _LOAD_INPUT_UTILS

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<iomanip>

class Input {
private:
    std::vector<std::vector<char>>* input_1;
    std::vector<int> input_2;

public:
    Input();
    ~Input();

    std::vector<std::vector<char>>* loadInput(std::string&);
    void printInput(std::vector<std::vector<char>>&) const;
};
