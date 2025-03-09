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


	void dfs(TreeNode* node, int& k)
	{
		if (!node)
			return;

		if (-1 != ret)
			return;

		dfs(node->left, k);

		k--;

		if (0 == k && -1 == ret)
		{
			ret = node->val;
			return;
		}

		dfs(node->right, k);
	}

	int ret = -1;


public:
	int kthSmallest(TreeNode* root, int k) {

		dfs(root, k);

		return ret;
	}
};

