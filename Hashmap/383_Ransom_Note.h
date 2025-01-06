class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {

		unordered_map<char, int> m;

		for (char c : magazine)
			m[c]++;

		for (char c : ransomNote)
		{
			if (0 == m.count(c) || 0 == m[c])
				return false;

			m[c]--;
		}

		return true;
	}
};