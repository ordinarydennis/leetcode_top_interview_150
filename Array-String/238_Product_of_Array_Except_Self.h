class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {

		int totalPro = 1;
		int zeroCount = 0;

		for (int n : nums)
		{
			if (0 == n)
			{
				zeroCount++;
			}
			else
			{
				totalPro *= n;
			}
		}


		vector<int> ret(nums.size());

		if (2 <= zeroCount)
		{
			return ret;
		}

		for(int i = 0; i < nums.size(); i++)
		{
			if (1 == zeroCount)
			{
				if (0 == nums[i])
					ret[i] = totalPro;
			}
			else
			{
				ret[i] = totalPro / nums[i];
			}
		}

		return ret;
	}
};

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {

		vector<int> left(nums.size());
		vector<int> right(nums.size());

		left[0] = nums[0];
		right[nums.size() - 1] = nums[nums.size() - 1];

		for (int i = 1; i < nums.size(); i++)
		{
			left[i] = nums[i] * left[i - 1];
		}

		for (int i = nums.size() - 2; 0 <= i; i--)
		{
			right[i] = nums[i] * right[i + 1];
		}

		vector<int> ret(nums.size());

		for (int i = 0; i < nums.size(); i++)
		{
			if (0 == i)
			{
				ret[i] = right[i + 1];
			}
			else if (nums.size() - 1 == i)
			{
				ret[i] = left[i - 1];
			}
			else
			{
				ret[i] = left[i - 1] * right[i + 1];
			}
		}

		return ret;
	}
};