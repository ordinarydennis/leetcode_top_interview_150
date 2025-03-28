//fail
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int cur = nums[0];
		int index = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			if (cur == nums[i])
			{
				while (i < nums.size() && cur == nums[i])
				{
					i++;
				}

				if (2 < i - index)
				{
					nums[index + 2] = nums[i];
				}	

				index = index + 2;
				cur = nums[i];
			}
			else
			{
				nums[index + 1] = nums[i];
				index++;
				cur = nums[i];
			}
		}
	}
};

//fail
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int cur = nums[0];
		int index = 0;

		for (int i = 1; i < nums.size(); i++)
		{
			if (cur == nums[i])
			{
				while (i < nums.size() && cur == nums[i])
				{
					i++;
				}

				if (2 <  i - index)
				{
					nums[i + 2] = nums[i];
					index = i;
					cur = nums[i];
				}
				else
				{
					cur = nums[i];
					index = i;
				}
			}
			else
			{
				index++;
				nums[index] = nums[i];
				cur = nums[i];
			}
			
		}
	}
};

//fail
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int cur = nums[0];
		int index = 0;


		for (int i = 1; i < nums.size(); i++)
		{
			int count = 1;

			while (cur == nums[i])
			{
				count++;
			}

			if (2 < count)
			{
				for (int c = 0; c < count; c++)
				{
					nums[i + 2 + c] = nums[i + count + c - 1];
				}
			}

			cur = nums[i + count - 1];
		}

	}
}

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int index = 1;
		int count = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == nums[i - 1])
			{
				count++;
			}
			else
			{
				count = 1;
			}

			if (count <= 2)
			{
				nums[index++] = nums[i];
			}
		}

		return index;
	}
};

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int index = 1;
		int count = 1;

		for(int i = 1; i < nums.size(); i++)
		{ 
			if (nums[i - 1] != nums[i])
			{
				nums[index] = nums[i];
				index++;
				count = 1;
			}
			else
			{
				count++;

				if (count <= 2)
				{
					nums[index] = nums[i];
					index++;
				}
			}

		}

		return index;
	}
};
 
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int index = 1;
		int count = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i - 1] != nums[i])
			{
				count = 1;
			}
			else
			{
				count++;
			}

			if (count <= 2)
			{
				nums[index++] = nums[i];
			}
		}

		return index;
	}
};



class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		int count = 1;

		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i - 1] == nums[i])
			{
				count++;
			}
			else
			{
				count = 1;
			}

			if (2 < count)
			{
				nums.erase(nums.begin() + i);
				i--;
			}
		}

		return nums.size();
	}
};
