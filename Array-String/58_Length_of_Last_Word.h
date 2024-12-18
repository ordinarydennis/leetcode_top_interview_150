class Solution {
public:
	int lengthOfLastWord(string s) {

		int firstIndex = -1;

		for (int i = s.size() - 1; 0 <= i; i--)
		{
			if (' ' == s[i])
			{
				if (-1 == firstIndex)
					continue;

				return firstIndex - i;
			}

			if (-1 == firstIndex)
				firstIndex = i;

		}

		return firstIndex - 0 + 1;
	}
};