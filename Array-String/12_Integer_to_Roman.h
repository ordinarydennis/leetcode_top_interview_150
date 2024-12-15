class Solution {
public:
	string intToRoman(int num) {

		std::map<int, string> m = {
			{1, "I"},
			{4, "IV"},
			{5, "V"},
			{9, "IX"},
			{10, "X"},
			{40, "XL"},
			{50, "L"},
			{90, "XC"},
			{100, "C"},
			{400, "CD"},
			{500, "D"},
			{900, "CM"}
			{1000, "M"},
		
		};

		string ret;

		int t = 1;
		while(0 < num)
		{
			int n = num % 10 * t;

			string str;

			while (n)
			{
				if (n >= 1000)
				{
					str += "M";
					n -= 1000;
				}
				else if (n >= 900)
				{
					str += "CM";
					n -= 900;
				}
				else if (n >= 500)
				{
					str += "D";
					n -= 500;
				}
				else if (n >= 400)
				{
					str += "CD";
					n -= 400;
				}
				else if (n >= 100)
				{
					str += "C";
					n -= 100;
				}
				else if (n >= 90)
				{
					str += "XC";
					n -= 90;
				}
				else if (n >= 50)
				{
					str += "L";
					n -= 50;
				}
				else if (n >= 40)
				{
					str += "XL";
					n -= 40;
				}
				else if (n >= 10)
				{
					str += "X";
					n -= 10;
				}
				else if (n >= 9)
				{
					str += "IX";
					n -= 9;
				}
				else if (n >= 5)
				{
					str += "V";
					n -= 5;
				}
				else if (n >= 4)
				{
					str += "IV";
					n -= 4;
				}
				else //if (n >= 1)
				{
					str += "I";
					n -= 1;
				}
			}

			ret = str + ret;

			num = num / 10;

			t *= 10;
		}

		return ret;
	}
};


class Solution {
public:
	string intToRoman(int num) {

		std::map<int, string, greater<int>> m = {
			{1, "I"},
			{4, "IV"},
			{5, "V"},
			{9, "IX"},
			{10, "X"},
			{40, "XL"},
			{50, "L"},
			{90, "XC"},
			{100, "C"},
			{400, "CD"},
			{500, "D"},
			{900, "CM"},
			{1000, "M"},
		};

		string ret;

		int t = 1;

		while (0 < num)
		{
			int n = num % 10 * t;

			string str;

			while (n)
			{
				for (const auto& [k, c] : m)
				{
					if (n >= k)
					{
						str += c;
						n -= k;
						break;
					}
				}
			}

			num = num / 10;
			t *= 10;
			ret = str + ret;
		}

		return ret;
	}
};