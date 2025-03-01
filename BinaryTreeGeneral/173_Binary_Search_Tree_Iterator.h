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
class BSTIterator {
public:
	BSTIterator(TreeNode* root)
		:mRoot(root) {

		dfs(mRoot);

	}

	void dfs(TreeNode* node)
	{
		if (!node)
			return;

		dfs(node->left);

		vec.push_back(node);

		dfs(node->right);
	}

	int next() {

		return hasNext() ? vec[index++]->val : 0;
	}

	bool hasNext() {

		return index < vec.size();

	}


private:
	TreeNode* mRoot = nullptr;
	std::vector<TreeNode*> vec;
	int index = 0;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
