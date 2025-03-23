class Solution {
public:
	string addBinary(string a, string b) {

		int az = a.size() - 1;
		int bz = b.size() - 1;

		int c = 0;

		string ret;

		while (0 <= az || 0 <= bz)
		{
			int n1 = 0;
			int n2 = 0;
			
			if (0 <= az)
				n1 = a[az] - '0';

			if (0 <= bz)
				n2 = b[bz] - '0';
			
			int sum = n1 + n2 + c;

			c = sum / 2;
			sum = sum % 2;
			
			ret = to_string(sum)  + ret;

			az--;
			bz--;
		}

		if (c)
		{
			ret = "1" + ret;
		}

		return ret;
	}
};