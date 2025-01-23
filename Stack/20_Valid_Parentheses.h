class Solution {
public:
	bool isValid(string s) {

		std::stack<char> st;

		for (int i = 0; i < s.size(); i++)
		{
			if ('(' == s[i] || '{' == s[i] || '[' == s[i])
			{
				st.push(s[i]);
				continue;
			}

			if (st.empty())
				return false;

			char c = st.top();
			st.pop();

			switch(s[i])
			{
			case ')':
				if ('(' != c)
				{
					return false;
				}
				break;
			case '}':
				if ('{' != c)
				{
					return false;
				}
				break;
			case ']':
				if ('[' != c)
				{
					return false;
				}
				break;
			}
		}

		return st.empty();
	}
};