class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {

		int left = 0;
		//int right = 0;
		int sum = 0;
		int ret = INT_MAX;

		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];

			while (i + 1 < nums.size() && sum < target)
			{
				sum += nums[++i];				
			}

			if (target <= sum)
			{
				ret = min(ret, i - left + 1);
			}
			
			while (left < nums.size() && target < sum)
			{
				sum -= nums[left];
				ret = min(ret, i - left + 1);
				left++;

			}

			if (target == sum)
			{
				ret = min(ret, i - left + 1);
			}
		}

		return ret == INT_MAX ? 0 : ret;
	}
};