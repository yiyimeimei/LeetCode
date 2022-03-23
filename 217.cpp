#include <unordered_map>

class Solution {
public:
    unordered_map<int, bool> map;
    bool containsDuplicate(vector<int>& nums) {
        int length = nums.size();
        for(int i = 0; i < length; ++i)
        {
            if(map.find(nums[i]) != map.end())
            {
                return true;
            }
            else
            {
                map.emplace(nums[i], true);
            }
        }
        return false;
    }
};