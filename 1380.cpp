class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        for(int i = 0; i < m; ++i)
        {
            int min = matrix[i][0];
            int minIndex = 0;
            for(int j = 1; j < n; ++j)
            {
                if(matrix[i][j] < min)
                {
                    min = matrix[i][j];
                    minIndex = j;
                }
            }
            bool lucky = true;
            for(int j = 0; j < m; ++j)
            {
                if(matrix[j][minIndex] > min)
                {
                    lucky = false;
                    break;
                }
            }
            if(lucky)
            {
                result.push_back(min);
            }
            
        }
        return result;
    }
};