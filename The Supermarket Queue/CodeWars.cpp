#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

long queueTime(std::vector<int> customers, int n) {
	
	if (customers.size() == 0) return 0;
	std::vector<int> que(n);
	long res = 0;
	int numOfCus = n;
	for (int i = 0; i < std::min(static_cast<int>(customers.size()), n); ++i)
		que[i] = customers[i];
	auto getMinAndAdd = [&](std::vector<int> &q) {
		//Ищем минимальное в массиве
		int min = q[0];
		for (int i = 1; i < q.size(); ++i) {
			if (q[i] < min)
				min = q[i];
		}
		//////////////////////////////////
		//Убираем из очереди закончивших и добавляем новых
		for (int i = 0; i < q.size(); ++i) {
			q[i] -= min;
			if (q[i] == 0 && numOfCus < customers.size()) {
				q[i] = customers[numOfCus];
				++numOfCus;
			}
		}
		///////////////////////////////////
		return min;
	};
	while (numOfCus < customers.size()) {
		res += getMinAndAdd(que);
	}
	int max = 0;
	for (int i = 0; i < n; ++i) {
		if (que[i] > max)
			max = que[i];
	}
	res += max;
	return res;
}

int main()
{
	std::cout << queueTime(std::vector<int>{1, 1, 1, 1, 1}, 1);
}
