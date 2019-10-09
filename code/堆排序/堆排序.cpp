// 堆排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<vector>
using namespace std;


void adjustdown(vector<int>& a, int k, int len) {
	if (k > len / 2) return;
	int max_index=2*k;
	if (2 * k + 1 <= len) {
		max_index = a[2 * k] > a[2 * k + 1] ? 2 * k : 2*k + 1;
	}
	if (a[k] < a[max_index]) {
		swap(a[k], a[max_index]);
		adjustdown(a, max_index, len);
	}
}
void max_heap(vector<int>& a, int len) {
	for (int i = len / 2; i > 0; i--) {
		adjustdown(a, i, len);
	}
}
void heap_sort(vector<int>& a, int len) {
	max_heap(a, len);
	cout << a[1] << ' ';
	for (int i = len; i >1; i--) {
		swap(a[1], a[i]);
		adjustdown(a, 1, i - 1);
		cout << a[1] << ' ';
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
	test.push_back(-1);
	for (int i = 0; i < 10; i++) {
		test.push_back(rand() % 100);
	}
	printfvec(test);
	max_heap(test, test.size() - 1);
	printfvec(test);
	heap_sort(test, test.size() - 1);
	//printfvec(test);
	return 0;
}

