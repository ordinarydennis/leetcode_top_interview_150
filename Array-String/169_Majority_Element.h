class Solution {
public:
	int majorityElement(vector<int>& nums) {

		std::unordered_map<int, int> m;

		int half = nums.size() / 2;

		for (int n : nums)
		{
			m[n]++;

			if (half < m[n])
			{
				return n;
			}
		}

		return -1;

	}
};

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int majorityCount = nums.size() / 2;

		for (int num : nums) {
			int count = 0;
			for (int elem : nums) {
				if (elem == num) {
					count += 1;
				}
			}

			if (count > majorityCount) {
				return num;
			}
		}

		return -1;
	}
};

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};