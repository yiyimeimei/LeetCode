class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1, len = nums.size();
        for(int i = 1; i < len; ++i)
        {
            if(nums[i] != nums[i - 1])
            {
                nums[j++] = nums[i];
            } 
        }
        return j;
    }
};