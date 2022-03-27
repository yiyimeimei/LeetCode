class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1, p;
        while(l < len && nums[l] == 0)
            ++l;
        while(r >= 0 && nums[r] == 2)
            --r;
        p = l;
        while(p <= r && l <= r)
        {
            if(nums[p] == 0)
            {
                int temp = nums[p];
                nums[p] = nums[l];
                nums[l] = temp;
                while(nums[l] == 0)
                    ++l;
                if(p < l)
                    p = l;
                if(nums[p] == 1)
                    ++p;
            }
            else if(nums[p] == 2)
            {
                int temp = nums[p];
                nums[p] = nums[r];
                nums[r] = temp;
                while(nums[r] == 2)
                    --r;
                if(nums[p] == 1)
                    ++p;
            }
            else
                ++p;

        }
    }
};