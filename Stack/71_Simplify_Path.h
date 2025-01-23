class Solution {
public:
	string simplifyPath(string path) {

		stack<string> st;

		string str;

		for (int i = 1; i <= path.size(); i++)
		{
			if (i < path.size() && '/' != path[i])
			{
				str += path[i];
				continue;
			}

			if ("." == str)
			{
				str.clear();
				continue;
			}

			if (str.empty())
			{
				continue;
			}

			if (".." == str) 
			{
				str.clear();
				if (!st.empty())
				{
					st.pop();
				}
				continue;
			}

			st.push(std::move(str));
		}

		string ret;

		while (!st.empty())
		{
			ret = st.top() + "/" + ret;
			st.pop();
		}

		if (ret.size() && '/' == ret.back())
		{
			ret.pop_back();
		}

		return "/"  + ret;
	}
};