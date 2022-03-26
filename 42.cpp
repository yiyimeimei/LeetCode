class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int *maxLeft, *maxRight;
        maxLeft = new int[len];
        maxRight = new int[len];
        maxLeft[0] = height[0];
        maxRight[len - 1] = height[len - 1];
        int sum = 0;
        for(int i = len - 2; i >= 0; --i)
        {
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        for(int i = 1; i < len - 1; ++i)
        {
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
            sum += (min(maxLeft[i], maxRight[i]) - height[i]);
        }
        return sum;
    }
};