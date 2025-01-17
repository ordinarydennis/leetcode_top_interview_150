class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {

		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 == m.count(nums[i]))
			{
				m[nums[i]] = i;
				continue;
			}

			if (i - m[nums[i]] <= k)
			{
				return true;
			}
			else
			{
				m[nums[i]] = i;
			}
		}

		return false;
	}
};

13

