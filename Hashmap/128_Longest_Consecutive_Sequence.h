
//n + nLogn
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {

		if (nums.empty())
		{
			return 0;
		}

		sort(nums.begin(), nums.end());

		int l = 1;
		
		int ret = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == nums[i - 1])
			{
				continue;
			}

			if (1 == nums[i] - nums[i - 1])
			{
				l++;
			}
			else
			{
				l = 1;
			}
			
			ret = std::max(ret, l);
		}

		return ret;
	}
};


//time coplexity n?

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {

		if (nums.empty())
		{
			return 0;
		}

		set<int> st;

		for (int i = 0; i < nums.size(); i++)
		{
			st.insert(nums[i]);
		}

		int l = 1;
		int ret = 1;

		auto it = st.begin();
		++it;
		for (; it != st.end(); ++it)
		{
			if (1 == (*it) - *prev(it))
			{
				l++;
			}
			else
			{
				l = 1;
			}
			ret = std::max(ret, l);
		}

		return ret;
	}
};