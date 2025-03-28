class Solution {
public:
	int rangeBitwiseAnd(int left, int right) {

		int num = 0xFFFFFFFF;

		for (int i = left; i <= right; i++)
		{
			int i2 = i;
			int n = 0;
			int c = 0;
			while (i2)
			{
				n |= (i2 % 2) << c++;
				i2 /= 2;
			}

			num = num & n;
		}

		return num;

	}
};