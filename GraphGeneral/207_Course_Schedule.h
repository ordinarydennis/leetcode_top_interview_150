class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

		unordered_map<int, int> m;

		for (auto v : prerequisites)
		{
			m[v[0]] = v[1];
		}

		int n = m[0];
		
		vector<bool> visit(numCourses);

		visit[0] = true;
		
		
		int count = 1;

		while(count < numCourses)
		{
			if (false == visit[n])
			{
				visit[n] = true;
				n = m[n];
				count++;
			}
			else
			{
				return false;
			}
		}
		
		return true;
	}
};
