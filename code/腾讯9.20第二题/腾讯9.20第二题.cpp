#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
vector<vector<int>> a;
int value(int c1, int c2, int c3, int count) {
	if (count >= a.size()) return 0;
	int val1 = a[count][c2] + value(c2, c1, c3, count + 1);
	int val2 = a[count][c3] + value(c3, c1, c2, count + 1);
	return min(val1, val2);
}
int main() {
	int n, temp;
	cin >> n;
	vector<int> b;
	while (n-- > 0) {
		for (int i = 0; i < 3; i++) {
			cin >> temp;
			b.push_back(temp);
		}
		a.push_back(b);
		b.clear();
	}
	int res = min(value(0, 1, 2, 1) + a[0][0], min(value(1, 0, 2, 1) + a[0][1], value(2, 0, 1, 1) + a[0][2]));
	cout << res;
	return 0;
}
