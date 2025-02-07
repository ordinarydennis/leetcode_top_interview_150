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

	void dfs(TreeNode* node, int preDepth)
	{
		if (!node) return;

		depth = max(++preDepth, depth);

		dfs(node->left, preDepth);
		dfs(node->right, preDepth);
	}

	int depth = 0;

public:
	int maxDepth(TreeNode* root) {

		dfs(root, 0);

		return depth;
	}
};
