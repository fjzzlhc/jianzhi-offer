#include<iostream>
using namespace std;
#include<vector>
//输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
//遍历链表，并使用头插法。
class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> a;
		ListNode* p = head;
		while (p != NULL) {
			a.insert(a.begin(), p->val);
			p = p->next;
		}

		return a;
	}
};