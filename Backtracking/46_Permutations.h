class Solution {


    void dfs(vector<int>& nums, vector<int>& list, vector<bool>& visit)
    {
        if (list.size() == nums.size())
        {
            ret.push_back(list);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (visit[i])
                continue;

            visit[i] = true;

            list.push_back(nums[i]);

            dfs(nums, list, visit);

            list.pop_back();

            visit[i] = false;
        }
    }


    vector<vector<int>> ret;

public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> list;

        vector<bool> visit(nums.size());

        dfs(nums, list, visit);

        return ret;
    }
};