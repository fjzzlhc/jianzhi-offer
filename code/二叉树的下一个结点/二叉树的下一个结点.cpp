
/*
题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

思路：
分成两种情况：
1.如果该节点有右孩子，那么就是遍历以其右孩子为起点的中序遍历的第一个节点
2.如果没有右孩子，那么其下一个节点有两种情况，
	a.第一种情况是该节点所在的子树都是其父节点的右子树，那么其下一个节点就是空
	b.第二种情况是该节点所在的子树有存在是其父节点的左子树，那么要求的节点的下一个节点就是第一个符合上述要求的父节点。
*/


#include<iostream>
using namespace std;

#include<vector>
#include<map>
#include<algorithm>




struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

/*
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};
*/
class Solution {
public:
	TreeLinkNode* right_first_node(TreeLinkNode* p) {
		while (p->left) {
			p = p->left;
		}
		return p;
	}
	TreeLinkNode* father_first_node(TreeLinkNode* p) {
		if (p->next == NULL) return NULL;
		if (p->next->left == p) return p->next;
		if (p->next->right == p) return father_first_node(p->next);
	}
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (pNode->right) {
			return right_first_node(pNode->right);
		}
		else {
			return father_first_node(pNode);
		}

	}
};

int main() {

	return 0;

}
