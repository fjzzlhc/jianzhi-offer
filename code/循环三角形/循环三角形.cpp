#include<iostream>
using namespace std;

#include<vector>

int countt = 1;
void inittrangle(vector < vector<int>>& a, int n) {
	for (int i = 1; i <= n; i++) {
		vector<int> temp(i, 0);
		a.push_back(temp);
		temp.clear();
	}
}

void solution(vector < vector<int>>& a, int n, int c,int k) {
	int le = a.size() - n * 3;
	int i, j,z;
	if (le < 0) return;
	for (i = 0; i < le; i++) {
		a[c + i][k] = countt;
		countt++;
	}
	for (j = 1; j < le; j++) {
		a[c + i - 1][k+j] = countt;
		countt++;
	}
	for (z = le - 2; z >= 1; z--) {
		a[c + z][k + z] = countt;
		countt++;
	}
	solution(a, n + 1, c + 2, k + 1);
}
void printresult(vector < vector<int>>& a) {
	for (auto it = a.begin(); it != a.end(); it++) {
		for (auto it2 = it->begin(); it2 != it->end(); it2++) {
			cout << *it2 << ' ';
		}
		cout << endl;
	}
}

int main() {
	vector < vector<int>> a;
	int n;
	cin >> n;
	inittrangle(a, n);
	solution(a, 0,0,0);
	printresult(a);

	

	return 0;
}