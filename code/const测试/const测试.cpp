
#include <iostream>
using namespace std;

int& fun(int&b) {
	b = 2;
	return b;
}

int main()
{
	int p = 1;
	const int a = 10;//a不可改
	const int* b = &p;//*b不可改，b可改
	int* const c = &p;//*b可改，b不可改

	int& k=fun(p);
	k = 4;
	cout << p;
	return 0;
}

