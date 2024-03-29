#include "pch.h"
#include <iostream>
#include <string>

std::string highestScoringWord(const std::string &str) {
	int max = 0, cnt = 0, maxA = 0, maxB = 0, localA = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] != ' ') {
			cnt += str[i] - 'a' + 1;
			if (i != 0 && str[i - 1] == ' ')
				localA = i;
		}
		if ((str[i] == ' ' || i == str.size() - 1) && cnt > max) {
			max = cnt;
			maxA = localA;
			str[i] == ' ' ? maxB = i - 1 : maxB = i;
		}
		if (str[i] == ' ')
			cnt = 0;
	}
	std::string res = "";
	for (int i = maxA; i <= maxB; ++i) {
		res = res + str[i];
	}
	return res;
}

int main()
{
	std::cout << highestScoringWord("man i need a taxi up to ubud");
}
