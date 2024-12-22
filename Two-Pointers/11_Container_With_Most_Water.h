class Solution {
public:
	int maxArea(vector<int>& height) {

		int left = 0;
		int right = height.size() - 1;

		int ret = INT_MIN;

		for (int i = 0; i < height.size(); i++)
		{
			if (height[right] < height[left])
			{
				ret = max(ret, (right - left) * height[right]);
				right--;
			}
			else
			{
				ret = max(ret, (right - left) * height[left]);
				left++;
			}
		}

		return ret;
	}
}; 