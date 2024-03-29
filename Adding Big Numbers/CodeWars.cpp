#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
std::string add(std::string a, std::string b) {
	int dop = 0;
	std::string result = a.size() > b.size() ? a : b;
	long i = a.size() - 1, j = b.size() - 1;
	long *uk = i > j ? &i : &j;
	for (i, j; i >= 0 && j >= 0; --i, --j) {
		int tmp = (a[i] - '0') + (b[j] - '0') + dop;
		dop = tmp >= 10 ? 1 : 0;
		result[*uk] = static_cast<char>((tmp % 10) + '0');
	}
	while (dop && *uk >= 0) {
		int tmp = (result[*uk] - '0') + dop;
		dop = tmp >= 10 ? 1 : 0;
		result[*uk] = static_cast<char>((tmp % 10) + '0');
		--*uk;
	}
	if (dop) { result = '1' + result; }
	for (int i = 0; i < result.size(); ++i)
	{
		if (result[i] != '0') {
			result.erase(0, i);
			break;
		}
	}
	return result;
}
int main()
{
	srand(time(NULL));
	int i = 0;
	std::string t = "", p = "";
	while (i++ < 100) {
		t = static_cast<char>((rand() % 10) + '0') + t;
		p = static_cast<char>((rand() % 10) + '0') + p;
		std::cout << t << ' ' << p << ": " << std::endl;
		std::cout << add(t, p) << std::endl;
		std::cout << "---------------------------------" << std::endl;
	}
	return 0;
}
