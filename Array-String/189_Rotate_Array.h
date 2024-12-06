class Solution {
public:
	void rotate(vector<int>& nums, int k) {

		int n = k % nums.size();

		if (0 == n)
			return;

		int a = nums.size() - n;

		vector<int> ret(nums.size());

		for (int i = a; i < a + nums.size(); i++)
		{
			int index = i % nums.size();

			ret[i - a] = nums[index];
		}

		nums = ret;

	}
};