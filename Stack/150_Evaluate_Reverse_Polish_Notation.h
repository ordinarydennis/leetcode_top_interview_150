class Solution {

public:
	int evalRPN(vector<string>& tokens) {

		std::stack<int> st;

		for (int i = 0; i < tokens.size(); i++)
		{
			if ("+" == tokens[i] || "-" == tokens[i] || "*" == tokens[i] || "/" == tokens[i])
			{
				int n2 = st.top();
				st.pop();
				int n1 = st.top();
				st.pop();

				if ("+" == tokens[i])
				{
					st.push(n1 + n2);
				}
				else if ("-" == tokens[i])
				{
					st.push(n1 - n2);
				}
				else if ("/" == tokens[i])
				{
					st.push(n1 / n2);
				}
				else if ("*" == tokens[i])
				{
					st.push(n1 * n2);
				}
			}
			else
			{
				st.push(atoi(tokens[i].c_str()));
			}
		}

		return st.empty() ? 0 : st.top();
	}
};