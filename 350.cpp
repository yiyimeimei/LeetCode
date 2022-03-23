#include <unordered_map>
class Solution {
public:
    unordered_map<int, int> map;
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> result;
        for(int i = 0; i < len1; ++i)
        {
            auto iter = map.find(nums1[i]);
            if(iter != map.end())
            {
                ++iter->second;
            }
            else
            {
                map.emplace(nums1[i], 1);
            }
        }
        for(int i = 0; i < len2; ++i)
        {
            auto iter = map.find(nums2[i]);
            if(iter != map.end())
            {
                result.push_back(nums2[i]);
                if(--iter->second == 0)
                {
                    map.erase(nums2[i]);
                }
            }
        }
        return result;
    }
};