//��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
//����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء�
//��������{ 3,4,5,1,2 }Ϊ{ 1,2,3,4,5 }��һ����ת�����������СֵΪ1��
//NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

//�и��õĽⷨ��͵��ֱ�ӱ����ˡ������������ٶȰ�
//�Ż���������۰뷨��
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
