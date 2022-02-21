class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count = 0;
        int length = nums.size();
        for(int i = 0; i < length; ++i)
        {
            for(int j = i + 1; j < length; ++j)
            {
                int tmp = nums[i] - nums[j];
                if(tmp == k || tmp == -k)
                {
                    ++count; 
                }
            }
        }
        return count;
    }
};