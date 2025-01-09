class Solution {
public:
	bool isAnagram(string s, string t) {

		unordered_map<char, int> m;

		for (char c : s)
			m[c]++;

		for (char c : t)
		{
			if (0 == m.count(c)) return false;

			if (0 == --m[c]) m.erase(c);			
		}

		return m.empty();
	}
};

class Solution {
public:
	bool isAnagram(string s, string t) {

		sort(s.begin(), s.end());
		sort(t.begin(), t.end());

		return s == t;
	}
};