class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {

		int begin = 0;
		int end = nums.size();

		while (begin < end)
		{
			int mid = (begin + end) / 2;

			if (nums[mid] == target)
				return mid;

			if (nums[mid] < target)
				begin = mid + 1;
			else
				end = mid;
		}

		return (begin + end) / 2;
	}
};