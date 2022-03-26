class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        unordered_set<int> set;
        for(int i = 0; i < len; ++i)
        {
            if(set.count(nums[i]) == 0)
            {
                set.insert(nums[i]);
            }
            else
            {
                set.erase(nums[i]);
            }
        }
        auto iter = set.begin();
        return *iter;
    }
};