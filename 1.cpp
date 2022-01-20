class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int firstIdx, secondIdx;
        int length = nums.size();
        bool flag = false;
        for(int i = 0; i < length; ++i)
        {
            for(int j = i + 1; j < length; ++j)
            {
                if(nums[i] + nums[j] == target)
                {
                    firstIdx = i;
                    secondIdx = j;
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        vector<int> res;
        res.push_back(firstIdx);
        res.push_back(secondIdx);
        return res;
    }
};