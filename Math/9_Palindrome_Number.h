class Solution {
public:
	bool isPalindrome(int x) {

		if (x < 0)
			return false;

		string str = to_string(x);

		int max = str.size() - 1;

		for (int i = 0; i < str.size() / 2; i++)
		{
			if (str[i] != str[max - i])
			{
				return false;
			}
		}

		return true;
	}
};

//fail
class Solution {
public:
	bool isPalindrome(int x) {

		if (x < 0)
			return false;

		int count = 0;
		int x2 = x;
		while (x2)
		{
			x2 = x2 / 10;
			count++;
		}


		while(2 <= count)
		{
			if (static_cast<int>(x / pow(10, count - 1)) != static_cast<int>(x % 10))
			{
				return false;
			}

			count -= 2;
			x = x % 10;
		}
		
		return true;
	}
};
