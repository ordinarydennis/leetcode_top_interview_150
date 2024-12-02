class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int curNum = nums[0];
		int nextIndex = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			if (curNum != nums[i])
			{
				nums[nextIndex] = nums[i];
				curNum = nums[i];
				nextIndex++;
			}
		}

		return nextIndex;
	}
};



