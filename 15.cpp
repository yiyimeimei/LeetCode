class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        int len = nums.size();
        if (len < 3)
            return result;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0)
            return result;
        for (int i = 0; i < len - 2; ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1, r = len - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    result.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while(l < r && nums[l] == nums[l + 1])
                        ++l;
                    while(l < r && nums[r - 1] == nums[r])
                        --r;
                    --r;
                    ++l;
                }
                else if(nums[i] + nums[l] + nums[r] > 0)
                {
                    --r;
                }
                else
                {
                    ++l;
                }
            }
        }
        return result;
    }
};