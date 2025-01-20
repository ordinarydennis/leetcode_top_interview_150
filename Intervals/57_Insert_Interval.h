class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

		vector<vector<int>> ret;

		if (intervals.empty())
		{
			ret.emplace_back(std::move(newInterval));
			return ret;
		}

		vector<int> overlapped;

		bool isInserted = false;

		for (int i = 0; i < intervals.size(); i++)
		{
			auto& interval = intervals[i];

			if (overlapped.empty())
			{
				if (interval[0] <= newInterval[0] && newInterval[1] <= interval[1])
				{
					isInserted = true;
					ret.emplace_back(std::move(interval));
					continue;
				}

				if (interval[1] < newInterval[0])
				{
					ret.emplace_back(std::move(interval));
					continue;
				}

				overlapped = vector<int> {
					std::min(interval[0], newInterval[0]),
					std::max(interval[1], newInterval[1])
				};
			}
			else
			{
				if (interval[0] <= overlapped[1])
				{
					overlapped[1] = std::max(interval[1], newInterval[1]);
				}
				else
				{
					ret.emplace_back(std::move(overlapped));
					ret.emplace_back(std::move(interval));
					isInserted = true;
				}
			}
		}

		if (false == isInserted)
		{
			ret.emplace_back(std::move(newInterval));
		}

		if (false == overlapped.empty())
		{
			ret.emplace_back(std::move(overlapped));
		}

		return ret;
	}
};