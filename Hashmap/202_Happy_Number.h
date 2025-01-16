class Solution {
public:
	bool isHappy(int n) {

		int num = n;

		while (1 != num)
		{
			int sum = 0;

			while(num)
			{
				int d = num % 10;

				if (1 == d)
					return false;

				sum += pow(d, 2);

				num = num / 10;
			}

			num = sum;

		}

		return 1 == num;
	}
};

class Solution {
public:
	bool isHappy(int n) {

		int num = n;

		unordered_set<int> set;

		while (1 != num && 0 == set.count(num))
		{
			set.insert(num);
			
			int sum = 0;

			while (0 < num)
			{
				int m = num % 10;
				sum += m * m;
				num = num / 10;
			}

			num = sum;
		}

		return 1 == num;

	}
};