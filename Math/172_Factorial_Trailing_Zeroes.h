class Solution {
public:
	int trailingZeroes(int n) {


		long long a = 1;
		for (long long i = 1; i <= n; i++)
		{
			a *= i;
		}

		cout<< "a: "<< a << endl;
		int ret = 0;

		while(a)
		{
			if (0 == a % 10)
			{
				ret++;
				a /= 10;
			}
			else
			{
				break;
			}	
		}

		return ret;

	}
};
