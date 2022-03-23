class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        vector<int> sorted;
        while(p1 < m && p2 < n)
        {
            if(nums1[p1] < nums2[p2])
            {
                sorted.push_back(nums1[p1]);
                ++p1;
            }
            else
            {
                sorted.push_back(nums2[p2]);
                ++p2;
            }
        }
        for(; p1 < m; ++p1)
        {
            sorted.push_back(nums1[p1]);
        }
        for(; p2 < n; ++p2)
        {
            sorted.push_back(nums2[p2]);
        }
        nums1 = sorted;
    }
};