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




class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {

		unordered_map<char, int> m;

		for (int i = 0; i < magazine.size(); i++)
		{
			m[magazine[i]]++;
		}

		for (int i = 0; i < ransomNote.size(); i++)
		{
			m[ransomNote[i]]--;
			if (m[ransomNote[i]] < 0)
			{
				return false;
			}
			
		}

		return true;
	}
};