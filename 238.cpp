class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int *front, *back;
        front = new int[n];
        back = new int[n];
        front[0] = 1;
        back[n - 1] = 1;
        for(int i = 1; i < n; ++i)
        {
            front[i] = front[i - 1] * nums[i - 1];
            back[n - 1 - i] = back[n - i] * nums[n - i];
        }
        vector<int> result(n);
        for(int i = 0; i < n; ++i)
        {
            result[i] = front[i] * back[i];
        }
        return result;
    }
};