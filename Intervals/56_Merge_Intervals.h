class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {

		std::sort(intervals.begin(), intervals.end());

		int start = intervals[0][0];
		int end = intervals[0][1];

		vector<vector<int>> ret;

		for (int i = 1; i <= intervals.size(); i++)
		{
			if (i == intervals.size() || end < intervals[i][0])
			{
				ret.emplace_back(vector<int> {start, end});

				if (i < intervals.size())
				{
					start = intervals[i][0];
					end = intervals[i][1];
				}
			}
			else
			{
				end = max(end, intervals[i][1]);
			}
		}

		return ret;
	}
};

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {

		std::sort(intervals.begin(), intervals.end());

		vector<vector<int>> ret;

		for (int i = 0; i < intervals.size(); i++)
		{
			if (ret.empty() || ret.back()[1] < intervals[i][0])
			{
				ret.push_back(intervals[i]);
			}
			else
			{
				ret.back()[1] = std::max(ret.back()[1], intervals[i][1]);
			}
		}

		return ret;
	}
};