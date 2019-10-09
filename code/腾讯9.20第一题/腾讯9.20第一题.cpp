#include<iostream>
using namespace std;

#include<vector>
#include<stack>
#include<string>
#include<queue>
#include<map>
#include<algorithm>

/*
1. 判断长度，过短的不行，长的记录下多出来个数times（即为可删除的个数）
2. 寻找前n个，如果含有8就可以
*/



int main() {
	int t, n, i;
	string str;
	cin >> t;
	
	while (t-- > 0) {
		cin >> n;
		cin >> str;
		if (str.size() < 11) {
			cout << "NO" << endl;
		}
		else
		{
			int times = str.size() - 11;
			for (i = 0; i <= times; i++) {
				if (str[i] == '8') {
					cout << "YES" << endl;
					break;
				}
			}
			if (i >= times) cout << "NO" << endl;
		}
	}
	return 0;

}
