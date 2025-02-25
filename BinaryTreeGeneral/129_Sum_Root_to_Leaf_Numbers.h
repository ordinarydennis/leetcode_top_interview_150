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

    void dfs(TreeNode* root, int sum)
    {
        sum += root->val;

		if (!root->left && !root->right)
		{
			ret += sum;
			return;
		}

        if (root->left)
            dfs(root->left, sum * 10);

        if (root->right)
            dfs(root->right, sum * 10);
    }


    int ret = 0;

public:
    int sumNumbers(TreeNode* root) {

        dfs(root, 0);

        return ret;
    }
};


6m