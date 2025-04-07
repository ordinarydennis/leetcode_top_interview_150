class Solution {

	bool dfs(int index, string& s, std::unordered_set<string>& wordMap)
	{
		if (memo.count(index))
		{
			return memo[index];
		}

		if (s.size() <= index)
		{
			return true;
		}

		bool result = false;

		for (int i = 1; i <= s.size(); i++)
		{
			const auto& sub = s.substr(index, i);

			if (0 == wordMap.count(sub))
			{
				continue;
			}

			if (false == dfs(index + i, s, wordMap))
			{
				continue;
			}
			else
			{
				result = true;
				break;
			}
		}

		return memo[index] = result;
	}


	std::unordered_map<int, bool> memo;


public:
	bool wordBreak(string s, vector<string>& wordDict) {

		std::unordered_set<string> wordMap(wordDict.begin(), wordDict.end());

		return dfs(0, s, wordMap);
	}
};