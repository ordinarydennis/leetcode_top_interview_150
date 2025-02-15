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

	bool dfs(TreeNode* node, int sum, int targetSum)
	{
		if (!node)
			return false;

		if (!node->left && !node->right)
			return node->val + sum == targetSum;

		return dfs(node->left, sum + node->val, targetSum) ||
			dfs(node->right, sum + node->val, targetSum);
	}


public:
	bool hasPathSum(TreeNode* root, int targetSum) {

		return dfs(root, 0, targetSum);

	}
};

