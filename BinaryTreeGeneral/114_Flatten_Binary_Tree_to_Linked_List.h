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

    TreeNode* dfs(TreeNode* node)
    {
        if (!node)
        {
            return nullptr;
        }

        auto* newNode = new TreeNode(node->val);

        newNode->right = dfs(node->left);

        auto* r = dfs(node->right);

        if (newNode->right)
        {
            newNode->right->right = r;
        }
        else
        {
            newNode->right = r;
        }
        
        return newNode;
    }
    

    void traversal(TreeNode* node)
    {

        if (!node)
        {
            return;
        }

        cout << node->val << endl;;

        traversal(node->left);
        traversal(node->right);

    }

public:
    void flatten(TreeNode* root) {

        root = dfs(root);

        traversal(root);

    }
};
