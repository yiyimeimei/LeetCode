class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 1;
        int result = nums[0];
        int len = nums.size();
        for (int i = 1; i < len; ++i)
        {
            if (!cnt)
            {
                result = nums[i];
                ++cnt;
            }
            else if (nums[i] != result)
            {
                --cnt;
            }
            else if(nums[i] == result)
                ++cnt;
        }
        return result;
    }
};