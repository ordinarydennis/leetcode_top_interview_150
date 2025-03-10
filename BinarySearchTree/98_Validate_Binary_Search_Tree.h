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

	int dfs(TreeNode* node, bool isLeft, bool& ret)
	{
		int l = INT_MIN;

		if (node->left)
		{
			l = dfs(node->left, true, ret);
		}

		int r = INT_MAX;

		if (node->right)
		{
			r = dfs(node->right, false, ret);
		}

		if (!ret)
		{
			return node->val;
		}

		if (l < node->val && node->val < r)
		{
			ret = true;

			if (isLeft)
			{
				return r == INT_MAX ? node->val : std::max(node->val, r);
			}
			else
			{
				return l == INT_MIN ? node->val : std::min(node->val, l);
			}
		}

		ret = false;

		return node->val;
	}


public:
	bool isValidBST(TreeNode* root) {

		bool ret = true;
		
		int l = dfs(root->left, true, ret);

		int r = dfs(root->right, false, ret);

		if (false == ret)
		{
			return false;
		}

		return l < root->val < r;
	}
};