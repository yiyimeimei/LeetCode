class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result;
        int len = nums.size();
        int minIndex = 0, minValue = abs(nums[0]);
        for(int i = 1; i < len; ++i)
        {
            if(nums[i] > 0 && nums[i] > minValue)
                break;
            if(abs(nums[i]) < abs(minValue))
            {
                minValue = abs(nums[i]);
                minIndex = i;
            }
        }
        result.push_back(minValue * minValue);
        int l = minIndex - 1, r = minIndex + 1;
        while(l >= 0 && r < len)
        {
            int left = abs(nums[l]);
            int right = abs(nums[r]);
            if(left < right)
            {
                result.push_back(left * left);
                --l;
            }
            else
            {
                result.push_back(right * right);
                ++r;
            }
        }
        while(l >= 0)
        {
            int left = abs(nums[l]);
            result.push_back(left * left);
            --l;
        }
        while(r < len)
        {
            int right = abs(nums[r]);
            result.push_back(right * right);
            ++r;
        }
        return result;


    }
};