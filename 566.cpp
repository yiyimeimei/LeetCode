class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> result;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> nums;
        if(m * n != r * c)
        {
            return mat;
        }
        for(int i = 0; i < m; ++i)
        {
            nums.insert(nums.end(), mat[i].begin(), mat[i].end());
        }
        int ptr = 0;
        auto iter = nums.begin();
        for(int i = 0; i < r; ++i)
        {
            vector<int> temp(iter, iter + c);
            iter = iter + c;
            result.push_back(temp);
        }
        return result;
    }
};