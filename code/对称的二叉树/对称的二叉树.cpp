
/*
题目描述
请实现一个函数，用来判断一颗二叉树是不是对称的。注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。

思路：左子树的左孩子和右子树的右孩子相等，左子树的右孩子和右子树的左孩子相等，符合这两个条件就是对称
*/


#include<iostream>
using namespace std;

#include<vector>
#include<map>
#include<algorithm>



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
*/
class Solution {
public:
	bool issmy(TreeNode* p, TreeNode* q) {
		if (!p && !q) {
			return true;
		}
		else if (p && q && (p->val == q->val)) {//防止p,q有一个是空指针，导致访问出错
			return issmy(p->left, q->right) && issmy(p->right, q->left);
		}
		else {
			return false;
		}
	}
	bool isSymmetrical(TreeNode* pRoot)
	{
		if (!pRoot) return true;
		return issmy(pRoot->left, pRoot->right);
	}
};




int main() {

	return 0;

}
