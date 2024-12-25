class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		int left = 0;

		unordered_set<char> st;
		
		int ret = 0;

		for (int i = 0; i < s.size(); i++)
		{
			while (st.count(s[i]))
				st.erase(s[left++]);

			st.insert(s[i]);

			ret = std::max(ret, static_cast<int>(st.size()));
		}

		return ret;
	}
};

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		unordered_map<char, int> m;

		int ret = 0;
		for (int i = 0, index = 0; i < s.size(); i++)
		{
			if (m.count(s[i]))
			{
				index = std::max(m[s[i]], index);
			}

			ret = std::max(ret, i - index + 1);
			
			m[s[i]] = i + 1;
		}

		return ret;

	}
};