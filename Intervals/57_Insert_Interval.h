class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

		vector<vector<int>> ret;

		int len = intervals.size();

		int i = 0;

		while (i < len && intervals[i][1] < newInterval[0])
		{
			ret.push_back(intervals[i++]);
		}

		while (i < len && intervals[i][0] <= newInterval[1])
		{
			newInterval[0] = std::min(newInterval[0], intervals[i][0]);
			newInterval[1] = std::max(newInterval[1], intervals[i][1]);
			i++;
		}

		ret.push_back(newInterval);

		while (i < len)
		{
			ret.push_back(intervals[i++]);
		}

		return ret;
	}
};


class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

		vector<vector<int>> ret;

		int len = intervals.size();

		int i = 0;

		while (i < len && intervals[i][1] < newInterval[0])
		{
			ret.push_back(intervals[i++]);
		}

		//intervals[i][1] >= newInterval[0]

		//�̷��� �ϸ� ������� ���� ���� interval�� ���ǿ� �ɸ��� �ȴ�. 
		//while (i < len && intervals[i][1] >= newInterval[0])
		
		//intervals[i][0] <= newInterval[1] ������ �Ʒ� ��Ȳ ó�� ���͹��� ���������� ���� �����̴�.
		//  ___              ___
		// |   |      ->    |   |
		//    |___|               |___|

		while (i < len && intervals[i][0] <= newInterval[1])
		{
			newInterval[0] = std::min(newInterval[0], intervals[i][0]);
			newInterval[1] = std::max(newInterval[1], intervals[i][1]);
			i++;
		}

		ret.push_back(newInterval);

		while (i < len)
		{
			ret.push_back(intervals[i++]);
		}

		return ret;
	}
};