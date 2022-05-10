class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len - 1, mid;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                if(mid - 1 < 0 || nums[mid - 1] < target)
                    return mid;
                r = mid - 1;
            }
            else
            {
                if(mid + 1 >= len || nums[mid + 1] > target)
                    return mid + 1;
                l = mid + 1;
            }
        }
        return mid;
    }
};