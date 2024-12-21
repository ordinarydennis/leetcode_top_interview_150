class Solution {
public:
	bool isSubsequence(string s, string t) {

		if (t.size() < s.size())
			return false;

		int i = 0;
		for (char c : t)
		{
			if (s[i] != c)
				continue;

			if (s.size() <= ++i)
				break;
		}

		return s.size() == i;
	}
};