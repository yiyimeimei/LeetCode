class Solution
{
public:
    static bool comp(int x, int y)
    {
        return x < y;
    }
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end(), comp);
        int len = nums.size();
        bool flag = true;
        int result;
        for (int i = 0; i < len && flag; ++i)
        {
            int l = i + 1, r = len - 1;
            int t = target - nums[i];
            while (l < r)
            {
                int sum = nums[l] + nums[r];
                if(abs(t - sum) < abs(target - result))
                    result = sum + nums[i];
                if(sum == t)
                {
                    flag = false;
                    result = target;
                    break;
                }
                else if(sum > t)
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

        /* unordered_set<int> set;
        for(int i = 0; i < len; ++i)
        {
            for(int j = i; j < len; ++j)
            {
                set.emplace(nums[i] + nums[j]);
            }
        }
        int k = 0;
        bool flag = true;
        while(flag)
        {
            for(int i = 0; i < len; ++i)
            {
                if(set.count(target - nums[i] - k) > 0)
                {
                    flag = false;
                    break;
                }
            }
        }
        return target - k; */
    }
};