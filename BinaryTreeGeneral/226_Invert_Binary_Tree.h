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
public:
	TreeNode* invertTree(TreeNode* root) {

		if (!root)
		{
			return nullptr;
		}

		queue<TreeNode*> q;

		q.push(root);

		while (q.size())
		{
			int size = q.size();

			vector<TreeNode*> v;

			for (int i = 0; i < size; i++)
			{
				auto* node = q.front();

				q.pop();

				v.push_back(node);

				if (node)
				{
					q.push(node->left);
				}
				
				if (node)
				{
					q.push(node->right);
				}
			}

			for (int i = 0; i < v.size() / 2; i++)
			{
				swap(v[i]->val, v[v.size() - i - 1]->val);
			}
		}

		return root;
	}
};