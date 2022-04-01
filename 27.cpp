#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int j = 0;
        for(int i = 0; i < len; ++i)
        {
            if(nums[i] != val)
            {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
int main()
{
    Solution s;
    vector<int> a{0,1,2,2,3,0,4,2};
    s.removeElement(a, 2);

}