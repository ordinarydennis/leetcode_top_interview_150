class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {

		int begin = 0;

		vector<string> ret;

		for (int i = 1; i <= nums.size(); i++)
		{
			if (i == nums.size() || nums[i - 1] + 1 != nums[i])
			{
				string str = (begin == i - 1) ? to_string(nums[begin]) : to_string(nums[begin]) + "->" + to_string(nums[i - 1]);

				ret.emplace_back(std::move(str));

				begin = i;
			}
		}

		return ret;
	}
};