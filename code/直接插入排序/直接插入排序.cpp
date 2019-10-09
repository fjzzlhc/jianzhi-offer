// 快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include<vector>
#include<random>
#include<algorithm>

void insertsort(vector<int>& a, int len) {
	int temp,i,j;
	for ( i = 0; i < len; i++) {
		temp = a[i];
		for ( j = i; j > 0; j--) {
			if (temp < a[j - 1]) {
				a[j] = a[j - 1];
			}
			else
			{
				break;
			}
		}
		a[j] = temp;
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
	insertsort(test, test.size());
	printfvec(test);
	return 0;
}

