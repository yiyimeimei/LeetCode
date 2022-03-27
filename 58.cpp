class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int len = n * n;
        int m = 0, i = 1;
        while(i <= len)
        {
            for(int x = m; x < n - m; ++x)
                result[m][x] = i++;
            for(int x = m + 1; x < n - m; ++x)
                result[x][n - m - 1] = i++;
            for(int x = n - m - 2; x >= m; --x)
                result[n - m - 1][x] = i++;
            for(int x = n - m - 2; x > m; --x)
                result[x][m] = i++;
            ++m;
        }
        return result;
    }
};