class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {

		if (strs.size() == 1)
		{
			return strs[0];
		}

		string ret;

		for (int ii = 0; ii < strs[0].size(); ii++)
		{
			int index = -1;

			for (int i = 1; i < strs.size(); i++)
			{
				if (strs[0].size() && strs[i].size() && strs[0][ii] == strs[i][ii])
				{
					index = i;
				}
				else
				{
					break;
				}
			}

			if (strs.size() - 1 == index)
			{
				ret += strs[0][ii];
			}
			else
			{
				break;
			}
		}

		return ret;
	}
};