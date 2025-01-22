class Solution {
public:
	int findMinArrowShots(vector<vector<int>>& points) {

		std::sort(points.begin(), points.end());
		
		vector<int> v = points[0];

		int ret = 0;

		for (int i = 1; i < points.size(); i++)
		{
			if (points[i][0] <= v[1])
			{
				v[0] = std::max(v[0], points[i][0]);
				v[1] = std::min(v[1], points[i][1]);
			}
			else
			{
				ret++;
				v = points[i];
			}

		}
		
		ret++;

		return ret;
	}
};