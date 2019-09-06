
/*
题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

思路：
每经过一个节点就记录一次他的出现次数，如果遍历过程中第一次出现遍历两次的节点，那么这个就是环的入口节点,
如果没有环，那么就肯定会遍历到链表尾部，这时候再输出NULL
*/


#include<iostream>
using namespace std;

#include<vector>
#include<map>
#include<algorithm>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
*/
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		map<ListNode*, int> a;
		while (pHead) {
			a[pHead]++;
			if (a[pHead] > 1) return pHead;
			pHead = pHead->next;
		}
		return NULL;
	}
};

int main() {

	return 0;

}
