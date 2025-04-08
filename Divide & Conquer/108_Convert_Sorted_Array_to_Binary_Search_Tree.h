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

    TreeNode* dfs(int start, int end, vector<int>& nums)
    {
        if (end < start)
            return nullptr;

        int mid = (start + end) / 2;

        auto* node = new TreeNode(nums[mid]);

        node->left = dfs(start, mid - 1, nums);
        node->right = dfs(mid + 1, end, nums);

        return node;
    }



public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        return dfs(0, nums.size() - 1, nums);

    }
};