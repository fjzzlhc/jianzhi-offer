#include<iostream>
using namespace std;

#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<map>
#include<algorithm>



vector<vector<int>> res;

void solution(vector<int> a,int l,int r) {
	if (l == r) res.push_back(a);
	for (int i = l; i <= r; i++) {
		swap(a[l], a[i]);
		solution(a, l+1,r );
		swap(a[l], a[i]);
	}
}
int dif_tall(vector<int> a) {
	int max_num = 0;
	for (auto it = a.begin(); it != a.end()-1; it++) {
		max_num = max(max_num,abs(*it-*(it+1)));
	}
	max_num = max(max_num, abs(a[0] - a[a.size() - 1]));
	return max_num;
}
vector<int> best_one() {
	vector<int> temp;
	int min = INT16_MAX;
	for (auto it = res.begin(); it != res.end(); it++) {
		int score = dif_tall(*it);
		if (min > score) {
			min = score;
			temp = *it;
		}
	}
	return temp;
}


int main() {
	vector<int> a;
	a.push_back(2);
	a.push_back(1);
	a.push_back(1);
	a.push_back(3);
	a.push_back(2);
	solution(a,0,a.size()-1);
	vector<int> k = best_one();
	for (auto it = k.begin(); it != k.end(); it++) {
		cout << *it << ' ';
	}
	cout << endl;
	return 0;

}


