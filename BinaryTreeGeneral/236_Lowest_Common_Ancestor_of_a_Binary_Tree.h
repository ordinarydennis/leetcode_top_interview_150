/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root)
        {
            return 0;
        }

        int l = dfs(root->left, p, q);
        int r = dfs(root->right, p, q);

        if (1 == l && 1 == r)
        {
            ret = root;
            return 2;
        }

        if (2 == l || 2 == r)
        {
            return 2;
        }

        int sum = l + r;

        if (root->val == p->val || root->val == q->val)
        {
            sum++;
            if (2 == sum)
            {
                ret = root;
            }
        }

        return sum;
    }

    TreeNode* ret = nullptr;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        dfs(root, p, q);

        return ret;

    }
};
