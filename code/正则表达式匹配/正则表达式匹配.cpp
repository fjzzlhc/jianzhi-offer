
/*
题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/
#include<iostream>
using namespace std;

#include<vector>
#include<string>

/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

1、考虑到“*”出现与否两种情况。
	（1）第一个字母出现*直接报错的
	（2）第二个字母为*时，有三种情况，字符串与*前面的字母匹配时，一是用*的无限匹配前面的字母功能，二是不适用他的这个功能，第三种情况是不匹配，那就直接跳过*
	（递归实现）
2、不出现“*”的情况
	两个字符一样或者模式串是“.”都直接匹配。
3、递归结束情况
	（1）两个字符串都为空，就是匹配成功
	（2）第一个字符串没空，第二个空了，那就匹配失败
	（3）匹配过程中不匹配，匹配失败
*/
class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0')
			return true;
		if (*str != '\0' && *pattern == '\0')
			return false;
		//if the next character in pattern is not '*'
		if (*(pattern + 1) != '*')
		{
			if (*str == *pattern || (*str != '\0' && *pattern == '.'))
				return match(str + 1, pattern + 1);
			else
				return false;
		}
		//if the next character is '*'
		else
		{
			if (*str == *pattern || (*str != '\0' && *pattern == '.'))
				return match(str, pattern + 2) || match(str + 1, pattern);
			else
				return match(str, pattern + 2);
		}
	}
};

int main() {
	Solution a;
	char str[] = "a";
	char pattern[] = ".*";
	cout<<a.match(str, pattern)<<endl;
	return 0;

}