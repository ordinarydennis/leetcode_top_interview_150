class Solution {
public:
	string reverseWords(string s) {

		std::reverse(s.begin(), s.end());

		string str;

		string ret;

		for (int i = 0; i <= s.size(); i++)
		{
			if(' ' == s[i] || s.size() == i)
			{
				if (0 < str.size())
				{
					reverse(str.begin(), str.end());
					ret += std::move(str) + " ";
				}
			}
			else
			{
				str += s[i];
			}
		}

		ret.pop_back();

		return ret;
	}
};