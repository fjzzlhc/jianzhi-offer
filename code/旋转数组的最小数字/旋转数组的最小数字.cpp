//把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
//例如数组{ 3,4,5,1,2 }为{ 1,2,3,4,5 }的一个旋转，该数组的最小值为1。
//NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

//有更好的解法，偷懒直接遍历了。但笔试重在速度吧
//优化版可以用折半法，
class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		int mini = INT32_MAX;
		if (rotateArray.empty()) return 0;
		vector<int>::iterator iter = rotateArray.begin();
		for (; iter != rotateArray.end(); iter++) {
			mini = mini>*iter ? *iter : mini;
		}
		return mini;
	}
};
