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