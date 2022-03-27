class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result;
        vector<int> t;
        t.push_back(1);
        result.push_back(t);
        for(int i = 1; i <= rowIndex; ++i)
        {
            vector<int> temp(i + 1);
            temp[0] = 1;
            temp[i] = 1;
            for(int j = 1; j < i; ++j)
            {
                temp[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(temp);
        }
        return result[rowIndex];
    }
};