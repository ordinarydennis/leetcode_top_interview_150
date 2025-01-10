
//fail
class Solution {
public:
	bool isIsomorphic(string s, string t) {

		if (s.size() != t.size())
		{
			return false;
		}


		vector<pair<char, int>> v1;
		vector<pair<char, int>> v2;

		for (int i = 0; i < s.size() - 1; i++)
		{
			int c = 1;
			while (i + 1 < s.size() && s[i] == s[i + 1])
			{
				c++;
				i++;
			}
			v1.emplace_back( pair<char, int> { s[i] , c } );
		}


		for (int i = 0; i < t.size() - 1; i++)
		{
			int c = 1;
			while (i + 1 < t.size() && t[i] == t[i + 1])
			{
				c++;
				i++;
			}
			v2.emplace_back(pair<char, int> { t[i], c });
		}

		if (v1.size() != v2.size())
		{
			return false;
		}

		for (int i = 0; i < v1.size(); i++)
		{
			cout << v1[i].first << " " <<v1[i].second<< ", ";
		}
		cout << endl;
		for (int i = 0; i < v2.size(); i++)
		{
			cout << v2[i].first << " " << v2[i].second << ", ";
		}

		cout << endl;


		for (int i = 0; i < v1.size(); i++)
		{
			if (v1[i].second != v2[i].second)
			{
				return false;
			}
			
		}

		return true;
	}
};


class Solution {
public:
	bool isIsomorphic(string s, string t) {

		if (s.size() != t.size())
		{
			return false;
		}

		unordered_map<char, int> m1;
		unordered_map<char, int> m2;

		int index;
		 
		for (int i = 0; i < s.size(); i++)
		{
			if (0 == m1.count(s[i]))
			{
				m1[s[i]] = index;
			}

			if (0 == m2.count(t[i]))
			{
				m2[t[i]] = index;
			}

			if (m1.count(s[i]) && m2.count(t[i]))
			{
				if (m1[s[i]] != m2[t[i]])
				{
					return false;
				}
			}
			else if (
				0 == m1.count(s[i]) && m2.count(t[i]) || 
					m1.count(s[i]) && 0 == m2.count(t[i])
				)
			{
				return false;
			}
			
			index++;
		}

		return true;
	}
};