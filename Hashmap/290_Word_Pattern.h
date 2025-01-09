class Solution {
public:
	bool wordPattern(string pattern, string s) {

		unordered_map<char, string> m;

		unordered_map<string, char> m2;

		string str;

		int index = 0;

		for (int i = 0; i <= s.size(); i++)
		{
			if (i < s.size() && ' ' != s[i])
			{
				str += s[i];
				continue;
			}

			if(i == s.size() || ' ' == s[i])
			{
				auto it = m.find(pattern[index]);
	
				if(m.end() == it)
				{
					if (m2.count(str))
					{
						return false;
					}

					m2[str] = pattern[index];
					m[pattern[index]] = str;					
				}
				else
				{
					auto it2 = m2.find(it->second);

					if (m2.end() == it2)
					{
						return false;
					}

					if (pattern[index] != it2->second)
					{
						return false;
					}
					
					if (it->second != str)
					{
						return false;
					}
				}
				str.clear();
				index++;
			}
		}

		return pattern.size() == m2.size();
	}
};

class Solution {
public:
	bool wordPattern(string pattern, string s) {

		if (pattern.size() == s.size())
		{
			return false;
		}


		string str;
		int index = 0;

		unordered_map<char, string> m1;
		unordered_map<string, char> m2;

		for (int i = 0; i <= s.size(); i++)
		{
			if (i < s.size() && ' ' != s[i])
			{
				str += s[i];
				continue;
			}

			if (i == s.size() && str.size() || ' ' == s[i] && str.size())
			{
				if (0 == m2.count(str) && 0 == m1.count(pattern[index]))
				{
					m1[pattern[index]] = str;
					m2[str] = pattern[index];
				}

				if (0 == m2.count(str) && m1.count(pattern[index]))
				{
					return false;
				}
				else if (m2.count(str) && m2[str] != pattern[index])
				{
					return false;
				}

				index++;
				str.clear();
			}

		}

		return true;
	}
};