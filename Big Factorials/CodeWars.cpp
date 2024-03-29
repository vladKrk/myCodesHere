#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

std::string factorial(int factorial) {
	if (factorial < 0) return "";
	if (factorial == 0) return "1";
	int dop = 0, dopNext = 0;
	std::string res = "1";
	for (int i = 2; i <= factorial; ++i) {
		for (int j = res.size() - 1; j >= 0; --j) {
			dopNext = ((res[j] - '0') * i + dop) / 10;
			res[j] = static_cast<char>((((res[j] - '0') * i + dop) % 10) + '0');
			dop = dopNext;
		}
		if (dop) {
			res = std::to_string(dop) + res;
			dop = 0;
			dopNext = 0;
		}
	}
	return res;
}

int main()
{
	std::cout << factorial(25);
}
