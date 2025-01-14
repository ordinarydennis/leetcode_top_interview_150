//fail
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {


		std::unordered_map<int, int> m;

		for (int i = 0 ; i < nums.size(); i++)
		{
			m[nums[i]] = i;
		}

		sort(nums.begin(), nums.end());

		int left = 0;
		int right = nums.size() - 1;

		while(left < right)
		{
			if (target == nums[left] + nums[right])
			{
				return vector<int> { m[nums[left]], m[nums[right]] };
			}
			else if (target < nums[left] + nums[right])
			{
				right--;
			}
			else
			{
				left++;
			}
			 
		}

		return {};
	}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash;
		for (int i = 0; i < nums.size(); i++) {
			hash[nums[i]] = i;
		}
		for (int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if (hash.find(complement) != hash.end() && hash[complement] != i) {
				return { i, hash[complement] };
			}
		}
		// If no valid pair is found, return an empty vector
		return {};
	}
};


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); i++)
			m[nums[i]] = i;


		for (int i = 0; i < nums.size(); i++)
		{
			auto it = m.find(target - nums[i]);
			if (m.end() == it || it->second == i)
				continue;
			
			return vector<int> { i, it->second };
		}

		return {};
	}
};

//one way
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); i++)
		{
			auto it = m.find(target - nums[i]);
			if (m.end() == it)
			{
				m[nums[i]] = i;
				continue;
			}

			return { i, it->second };	
		}

		return {};
	}
};