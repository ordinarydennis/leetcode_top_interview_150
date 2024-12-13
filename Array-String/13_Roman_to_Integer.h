class Solution {
public:
	int romanToInt(string s) {

		std::unordered_map<string, int> m = {
			{"I", 1},
			{"IV", 4},
			{"V", 5},
			{"VI", 6},
			{"IX", 9},
			{"X", 10},
			{"XL", 40},
			{"L", 50},
			{"XC", 90},
			{"C", 100},
			{"CD", 400},
			{"D", 500},
			{"CM", 900},
			{"M", 1000},
		};

		int n = 0;

		for (int i = 0; i < s.size();)
		{
			int l = 2;

			while (0 < l && i < s.size())
			{
				auto str = s.substr(i, l);
				auto it = m.find(str);
				if (m.end() == it)
				{
					l--;
					continue;
				}

				n += it->second;

				i += l;
				break;
			}
		}

		return n;
	}
};