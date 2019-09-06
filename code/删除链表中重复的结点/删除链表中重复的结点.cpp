
/*
题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

思路：
主要是删除的方法应该怎么定义。在这里使用p和q指示删除范围
1.开始时将p置为NULL,将q置为pHead
2.将情况分作需要删除和不需要删除的两种情况，需要删除的情况即出现节点的值相同的情况，此时继续遍历：p=p->next；直至p->val!=p->next->val；然后删除p到q之间的节点(p,q]
  不需要删除即节点的值不相同，这时候令：p=q;q=q->next;
3、删除也分两种情况，p为空或者p不为空。p为空则只需要改变头指针，p不为空则要改变p->next的值；
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
	void remove_same_node(ListNode*& p, ListNode*& q, ListNode*& head) {
		if (p == NULL) {
			q = q->next;
			head = q;
		}
		else {
			q = q->next;
			p->next = q;
		}
	}
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* p = NULL, * q = pHead;
		if (!q) return pHead;
		while (q && q->next) {
			if (q->val == q->next->val) {
				while ((q->next != NULL) && (q->val == q->next->val))
				{
					q = q->next;
				}
				remove_same_node(p, q, pHead);
			}
			else {
				p = q;
				q = q->next;
			}
		}

		return pHead;
	}
};


int main() {

	return 0;

}