class Solution {

	void dfs(string& digits ,int index, std::unordered_map<int, string>& m, string str, vector<string>& ret)
	{
		if (index == digits.size())
		{
			ret.push_back(str);
			return;
		}

		const auto& list = m[digits[index] - '0'];

		for (int i = 0; i < list.size(); i++)
		{
			dfs(digits, index + 1, m, str + list[i], ret);
		}
	}


public:
	vector<string> letterCombinations(string digits) {

		if (digits.empty())
			return {};

		std::unordered_map<int, string> m = {
			{2, "abc"},
			{3, "def"},
			{4, "ghi"},
			{5, "jkl"},
			{6, "mno"},
			{7, "qprs"},
			{8, "tuv"},
			{9, "wxyz"}
		};

		vector<string> ret;

		string str;

		dfs(digits, 0, m, str, ret);

		return ret;
	}
};

