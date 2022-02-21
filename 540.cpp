class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int length = nums.size();
        int l = 0, r = length - 1, m;
        while(l < r)
        {
            m = (l + r) / 2;
            if(m % 2 == 1)
            {
                --m;//如果m是奇数，要变成偶数
            }
            if(nums[m] == nums[m + 1])//说明单个数在右边
            {
                l = m + 2;
            }
            else//说明单个数在左边
            {
                r = m;
            }
        }
        return nums[l];
        
    }
};