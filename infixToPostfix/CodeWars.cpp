#include "pch.h"
#include <iostream>
#include <string>
#include <vector>


std::string to_postfix(std::string str) {
	std::vector<char> operations;
	std::string result = "";
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= '0' && str[i] <= '9') result += str[i];
		else if (str[i] == '+' || str[i] == '-') {
			while (!operations.empty() && operations.back() != '(') { result += operations.back(); operations.pop_back(); }
			operations.push_back(str[i]);
		}
		else if (str[i] == '*' || str[i] == '/') {
			while (!operations.empty() && (operations.back() != '(' && operations.back() != '+' && operations.back() != '-')) { result += operations.back(); operations.pop_back(); }
			operations.push_back(str[i]);
		}
		else if (str[i] == '^' || str[i] == '(') operations.push_back(str[i]);
		else if (str[i] == ')') {
			while (operations.back() != '(') { result += operations.back(); operations.pop_back(); }
			operations.pop_back();
		}
	}
	while (!operations.empty()) { result += operations.back(); operations.pop_back(); }
	return result;
}

int main()
{
	std::cout << to_postfix("5+(6-2)*9+3^(7-1)");
}
