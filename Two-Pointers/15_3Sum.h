class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

	}
};


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		sort(nums.begin(), nums.end());

		vector<vector<int>> ret;

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 == i || nums[i - 1] != nums[i])
			{
				int left = i + 1;
				int right = nums.size() - 1;

				while (left < right)
				{
					int sum = nums[i] + nums[left] + nums[right];
					if (0 < sum)
					{
						right--;
					}
					else if (sum < 0)
					{
						left++;
					}
					else
					{
						ret.push_back(vector<int>{ nums[i], nums[left], nums[right] });

						left++;
						right--;

						while(left < right && nums[left - 1] == nums[left])
							left++;
					}
				}
			}
		}

		return ret;
	}
};