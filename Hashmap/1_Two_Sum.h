//fail
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {


		std::unordered_map<int, int> m;

		for (int i = 0 ; i < nums.size(); i++)
		{
			m[nums[i]] = i;
		}

		sort(nums.begin(), nums.end());

		int left = 0;
		int right = nums.size() - 1;

		while(left < right)
		{
			if (target == nums[left] + nums[right])
			{
				return vector<int> { m[nums[left]], m[nums[right]] };
			}
			else if (target < nums[left] + nums[right])
			{
				right--;
			}
			else
			{
				left++;
			}
			 
		}

		return {};
	}
};