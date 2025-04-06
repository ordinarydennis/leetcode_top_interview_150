class Solution {
public:
	int rob(vector<int>& nums) {

		int len = nums.size();

		vector<int> v(len);

		v[len - 1] = nums[len - 1];

		for (int i = len - 2; 0 <= i; i--)
		{
			int a = 0;

			if (i + 2 < len)
			{
				a = v[i + 2];
			}


			v[i] = std::max(
				nums[i] + a,
				v[i + 1]
			);
		}

		return v[0];
	}
};
