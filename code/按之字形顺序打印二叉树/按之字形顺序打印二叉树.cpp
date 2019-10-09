
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
#include<deque>



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		vector<vector<int> > res;
		if (!pRoot) return res;
		deque<TreeNode*> mydeq;
		TreeNode* endnode = pRoot, * p;
		mydeq.push_back(pRoot);
		bool tag = 0;
		vector<int> temp;
		while (!mydeq.empty()) {
			if (tag == 0) {
				p = mydeq.front();
				mydeq.pop_front();
				if(p->left) mydeq.push_back(p->left);
				if (p->right) mydeq.push_back(p->right);
				temp.push_back(p->val);
			}
			else
			{
				p = mydeq.back();
				mydeq.pop_back();
				if (p->right) mydeq.push_front(p->right);
				if (p->left) mydeq.push_front(p->left);
				temp.push_back(p->val);
			}
			if (p == endnode) {
				if (!tag) endnode = mydeq.front();
				else endnode = mydeq.back();
				tag = !tag;
				res.push_back(temp);
				temp.clear();
				
			}
		}
		
		
		return res;

	}
};
void f(){}




int main() {

	return 0;

}
