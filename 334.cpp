//贪心
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        int first = nums[0], second = 2147483647;
        for(int i = 0; i < len; ++i)
        {
            if(nums[i] > second)
                return true;
            else if(nums[i] > first)
            {
                second = nums[i];
            }
            else if(nums[i] < first)
            {
                first = nums[i];
            }
        }
        return false;
    }
};