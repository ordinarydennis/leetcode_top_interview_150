class Solution {
public:
	bool isPalindrome(string s) {

		int left = 0;
		int right = s.size() - 1;

		while (left < right)
		{
			while (left < right && !(
					('0' <= s[left] && s[left] <= '9') ||
					('a' <= s[left] && s[left] <= 'z') ||
					('A' <= s[left] && s[left] <= 'Z'))
				)
			{
				left++;
			}

			while (left < right && !(
				('0' <= s[right] && s[right] <= '9') ||
				('a' <= s[right] && s[right] <= 'z') ||
				('A' <= s[right] && s[right] <= 'Z'))
			)
			{
				right--;
			}

			if (right <= left)
			{
				break;
			}

			if ('A' <= s[left] && s[left] <= 'Z')
			{
				s[left] = (s[left] - 'A') + 'a';
			}

			if ('A' <= s[right] && s[right] <= 'Z')
			{
				s[right] = (s[right] - 'A') + 'a';
			}

			if (s[left] != s[right])
			{
				return false;
			}

			left++;
			right--;
		}

		return true;
	}
};