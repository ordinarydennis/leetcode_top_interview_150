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

	TreeNode* dfs(int rootIndex, int begin, int end, vector<int>& preorder, vector<int>& inorder)
	{
		if (end < begin)
		{
			return nullptr;
		}

		auto root = new TreeNode(preorder[rootIndex]);

		int rootIndexInorder;

		for(int i = begin; i <= end; i++)
		{
			if (inorder[i] == preorder[rootIndex])
			{
				rootIndexInorder = i;
				break;
			}			
		}

		root->left = dfs(rootIndex + 1, begin, rootIndexInorder - 1, preorder, inorder);
		if (root->left)
		{
			root->right = dfs(rootIndex + 2, rootIndexInorder + 1, end, preorder, inorder);
		}
		else
		{
			root->right = dfs(rootIndex + 1, rootIndexInorder + 1, end, preorder, inorder);
		}
		

		return root;
	}


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		return dfs(0, 0, preorder.size() - 1, preorder, inorder);
    }
};