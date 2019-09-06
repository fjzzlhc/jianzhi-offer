
/*
题目描述
请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。

思路：
每次输入一个字符，都相应将出现次数记录在map里面，如果出现次数为一，就入队列，如果出现超过一，就从队列中删除。
输出时，如果队列不为空，就输出队首的值，如果为空，就说明没有存在出现一次的字符，返回#
*/


#include<iostream>
using namespace std;

#include<vector>
#include<map>
#include<algorithm>

class Solution
{
public:
	//Insert one char from stringstream
	//Solution():mymap(0,0),target('#'){}
	void Insert(char ch)
	{
		mymap[ch]++;
		if (mymap[ch] == 1) {
			myvec.push_back(ch);
		}
		else {
			vector<char>::iterator it = find(myvec.begin(), myvec.end(), ch);
			if (it != myvec.end()) myvec.erase(it);
		}

	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		if (!myvec.empty()) return myvec[0];
		else return '#';
	}
private:
	map<char, int> mymap;
	vector<char> myvec;
};


int main() {

	return 0;

}