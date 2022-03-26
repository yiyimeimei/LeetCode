#include <unordered_set>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row;
        unordered_set<int> col;
        int len1 = matrix.size();
        int len2 = matrix[0].size();
        for(int i = 0; i < len1; ++i)
        {
            for(int j = 0; j < len2; ++j)
            {
                if(matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto iter = row.begin(); iter != row.end(); ++iter)
        {
            for(int i = 0; i < len2; ++i)
            {
                matrix[*iter][i] = 0;
            }
        }
        for(auto iter = col.begin(); iter != col.end(); ++iter)
        {
            for(int i = 0; i < len1; ++i)
            {
                matrix[i][*iter] = 0;
            }
        }
    }
};