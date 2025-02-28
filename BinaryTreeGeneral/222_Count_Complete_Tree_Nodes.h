/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {

	void dfs(TreeNode* root)
	{
		if (!root)
			return;

		ret++;

		dfs(root->left);
		dfs(root->right);
	}


	int ret = 0;

public:
	int countNodes(TreeNode* root) {

		dfs(root);
		return ret;

	}
};