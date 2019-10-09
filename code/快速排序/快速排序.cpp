// 快速排序.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include<vector>
#include<random>
#include<algorithm>

int partition(vector<int>& a, int low, int high) {
	int temp = a[low];
	while (low < high) {
		while (low < high && a[high] >= temp) high--;
		a[low] = a[high];
		while (low < high && a[low] <= temp) low++;
		a[high] = a[low];
	}
	a[low] = temp;
	return low;
}
void quicksort(vector<int>& a, int low, int high) {
	if (low < high) {
		int pos = partition(a, low, high);
		quicksort(a, low, pos - 1);
		quicksort(a, pos + 1, high);
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
	quicksort(test, 0, test.size() - 1);
	printfvec(test);
	sort(test.begin(), test.end(), [](int a, int b) {return a > b; });
	printfvec(test);
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
