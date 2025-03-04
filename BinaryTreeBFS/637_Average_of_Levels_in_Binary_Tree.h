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
	vector<double> averageOfLevels(TreeNode* root) {

		if (!root)
			return {};

		std::queue<TreeNode*> q;

		q.push(root);
		
		vector<double> ret;

		while (q.size())
		{
			int sz = q.size();

			double sum = 0;

			for (int i = 0; i < sz; i++)
			{
				auto* node = q.front();
				q.pop();

				sum += node->val;

				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}

			ret.push_back(sum / sz);
		}

		return ret;
	}
};