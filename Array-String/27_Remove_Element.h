
//8m
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        for (int i = 0; i < nums.size(); i++)
        {
            if (val == nums[i])
            {
                nums.remove(i);
                i--;
            }
        }

        return nums.size();

    }
};


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int indexVal = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            while (i < nums.size() && val != nums[i])
            {
                i++;
            }

            if (nums.size() <= i)
            {
                break;
            }

            indexVal = i;

            i++;

            while (i < nums.size() && val == nums[i])
            {
                i++;
            }

            if (nums.size() <= i)
            {
                break;
            }

            swap(nums[indexVal], nums[i]);

            i = indexVal;
        }

        return indexVal;
    }
};