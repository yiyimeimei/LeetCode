class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int len1 = img.size();
        int len2 = img[0].size();
        vector<vector<int>> result(len1, vector<int>(len2));
        for(int i = 0; i < len1; ++i)
        {
            for(int j = 0; j < len2; ++j)
            {
                result[i][j] = filter(img, len1, len2, i, j);
            }
        }
        return result;
    }
    int filter(vector<vector<int>>& img, int m, int n, int x, int y)
    {
        int sum = 0;
        int cnt = 0;
        for(int i = x - 1; i <= x + 1; ++i)
        {
            if(i < 0 || i >= m)
            {
                continue;
            }
            for(int j = y - 1; j <= y + 1; ++j)
            {
                if(j < 0 || j >= n)
                {
                    continue;
                }
                sum += img[i][j];
                ++cnt;
            }
        }
        return sum / cnt;

    }
};