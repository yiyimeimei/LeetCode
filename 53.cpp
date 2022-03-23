class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum;
        int length = nums.size();
        int result = nums[0];
        sum.push_back(nums[0]);
        for(int i = 1; i < length; ++i)
        {
            int cur = max(sum[i - 1] + nums[i], nums[i]);
            sum.push_back(cur);
            if(cur > result)
            {
                result = cur;
            }
        }
        return result;
    }
};