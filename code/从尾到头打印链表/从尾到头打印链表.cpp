#include<iostream>
using namespace std;
#include<vector>
//����һ�������������β��ͷ��˳�򷵻�һ��ArrayList��
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
//����������ʹ��ͷ�巨��
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