class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int result = 0;
        while(l < r)
        {
            if(height[l] < height[r])
            {
                result = max(result, (r - l) * height[l]);
                ++l;
            }
            else
            {
                result = max(result, (r - l) * height[r]);
                --r;
            }
        }
        return result;
    }
};
//贪心算法 双指针向内缩进，每次较低height的向内缩