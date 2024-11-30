
//time complexity m + n
//space complexity m + n
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		vector<int> ret(m + n, 0);

		int index1 = 0;
		int index2 = 0;

		int i = 0;
		while (index1 < m || index2 < n)
		{
			if (index1 < m && index2 < n)
			{
				if (nums1[index1] < nums2[index2])
				{
					ret[i++] = nums1[index1++];
				}
				else
				{
					ret[i++] = nums2[index2++];
				}
			}
			else if (index2 < n)
			{
				ret[i++] = nums2[index2++];
			}
			else if(index1 < m)
			{
				ret[i++] = nums1[index1++];
			}
		}

		nums1 = ret;
	}
};


//time complexity m^2
//space comlexity 1
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		int index1 = 0;
		int index2 = 0;

		int last = m;
		for (int i2 = 0; i2 < n; i2++)
		{
			for (int i = 0; i < last; i++)
			{
				if (nums2[i2] < nums1[i])
				{
					swap(nums2[i2], nums1[i]);
				}
			}

			if (last < nums1.size())
			{
				nums1[last++] = nums2[i2];
			}
		}
	}
};


class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

		for (int i = m + n - 1; 0 <= i; i--)
		{
			if (n <= 0)
			{
				break;
			}

			if (0 < m && nums1[m - 1] > nums2[n - 1])
			{
				nums1[i] = nums1[m - 1];
				m--;
			}
			else if(0 < n)
			{
				nums1[i] = nums2[n - 1];
				n--;
			}
		}

	}
};