// 快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include<vector>
#include<random>
#include<algorithm>

void bubsort(vector<int>& a, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
}
void printfvec(const vector<int> a) {
	for (auto it = a.begin(); it != a.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
}
int main()
{
	vector<int> test;
	for (int i = 0; i < 20; i++) {
		test.push_back(rand() % 100);
	}
	printfvec(test);
	bubsort(test, test.size());
	printfvec(test);
	return 0;
}

