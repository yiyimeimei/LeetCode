#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int length = nums.size();
        unordered_map<int, int> dictionary;
        for(int i = 0; i < length; ++i)
        {
            if(dictionary.count(nums[i]) &&  ((i - dictionary[nums[i]]) <= k))
                return true;
            dictionary[nums[i]] = i;
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> a;
    a.push_back(1);
    a.push_back(0);
    a.push_back(1);
    a.push_back(1);
    cout<<s.containsNearbyDuplicate(a, 1);
}