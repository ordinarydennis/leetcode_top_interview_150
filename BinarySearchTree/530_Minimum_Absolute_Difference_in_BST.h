
class Solution {

	void dfs(TreeNode* node)
	{
		if (node->left)
		{
			ret = std::min(
				ret,
				std::abs(node->val - node->left->val)
			);
			dfs(node->left);
		}

		if (node->right)
		{
			ret = std::min(
				ret,
				std::abs(node->val - node->right->val)
			);
			dfs(node->right);
		}
	}

	int ret = INT_MAX;

public:
	int getMinimumDifference(TreeNode* root) {

		dfs(root);

		return ret;
	}
};


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


	void dfs(TreeNode* node)
	{
		if (node->left)
		{
			auto* lnode = node->left;
			int value1 = -1;
			while (lnode)
			{
				value1 = lnode->val;
				lnode = lnode->right;
			}
			if (-1 != value1)
			{
				ret = std::min(
					ret,
					std::abs(node->val - value1)
				);
			}

			dfs(node->left);
		}

		if (node->right)
		{
			auto* rnode = node->right;
			int value1 = -1;
			while (rnode)
			{
				value1 = rnode->val;
				rnode = rnode->left;
			}

			if (-1 != value1)
			{
				ret = std::min(
					ret,
					std::abs(node->val - value1)
				);
			}
			dfs(node->right);
		}

	}

	int ret = INT_MAX;

public:
	int getMinimumDifference(TreeNode* root) {

		dfs(root);

		return ret;
	}
};