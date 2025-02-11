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
	bool isSymmetric(TreeNode* root) {

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
					q.push(node->right);
				}
			}

			for (int i = 0 ; i < v.size() / 2; i++)
			{
				auto left = v[i];
				auto right = v[v.size() - i - 1];

				if (left && right)
				{
					if (left->val != right->val)
					{
						return false;
					}
				}
				else
				{
					if (!left && right ||
						left && !right)
					{
						return false;
					}
				}
			}
		}

		return true;
	}
};