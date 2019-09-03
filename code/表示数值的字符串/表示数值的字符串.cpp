#include<iostream>
using namespace std;

#include<vector>
#include<string>
//题目描述
//请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100", "5e2", "-123", "3.1416"和"-1E-16"都表示数值。 但是"12e", "1a3.14", "1.2.3", "+-5"和"12e+4.3"都不是。
/*
思路：
遍历整个字符串，如果途中遇到不符合要求的，则输出0，如果遍历完都符合，则输出1
1、正负符号只有在开头和出现E或者e的情况下出现，先处理首部为+ -情况；
2、在处理完 1、 之后，如果之后出现连续数字，都不出错；
3、如果不是2、的情况，这时候如果是出现了E或者e的情况，就判断e后出现的第一个字符是不是数字或者第一个字符是+ -且第二个字符是数字的情况，如果是，符合规定继续往下遍历；这时候还要锁定不能再出现 . 的情况了，用tag实现
4、在2、3都不满足的情况下，如果出现了 . 且出现 . 的情况还没有被锁定，这时候如果 . 的后面接的时数字，那么就不报错，继续往下遍历，并且此时就不能再出现 . 了，将tag置为1；
5、其他情况就全都不满足，直接返回0；
*/
class Solution {
public:
	bool isNumeric(char* string)
	{
		int pos;
		bool tag = 0;
		if (!string) return false;
		if (string[0] == '+' || string[0] == '-') {
			pos = 1;
		}
		else if (string[0]<'0' || string[0]>'9') {
			return false;
		}
		else {
			pos = 0;
		}
		while (string[pos] != '\0') {
			if (string[pos] >= '0' && string[pos] <= '9') pos++;
			else if (string[pos] == 'e' || string[pos] == 'E') {
				tag = 1;
				if (string[pos + 1] == '\0') return false;
				else if (string[pos + 1] >= '0' && string[pos + 1] <= '9') {
					pos++;
				}
				else if (string[pos + 1] == '-'|| string[pos + 1] == '+') {
					if (string[pos + 2] >= '0' && string[pos + 2] <= '9') {
						pos += 2;
						
					}
					else return false;
				}
				else return false;
			}
			else if (string[pos] == '.'&&!tag) {
				if (string[pos + 1] >= '0' && string[pos + 1] <= '9') {
					pos++;
					tag = 1;
				}
				else return false;
			}
			else return false;
		}
		return true;
	}

};

int main() {
	Solution a;
	char k[] = "123.45e+6";

	cout << a.isNumeric(k)<<endl;

	return 0;
}