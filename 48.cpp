#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int times = n / 2;
        for(int i = 0; i < times; ++i)
        {
            int *temp = new int[n];
            for(int j = i; j < n - i; ++j)
            {
                temp[j] = matrix[i][j];
            }
            for(int j = n - i - 1; j >= i; --j)
            {
                matrix[i][j] = matrix[n - 1 - j][i];
            }
            for(int j = n - i - 1; j >= i; --j)
            {
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 -j];
            }
            for(int j = n - i - 1; j >= i; --j)
            {
                matrix[n - 1 - i][n - 1 -j] = matrix[j][n - 1 - i];
            }
            for(int j = n - i - 1; j >= i; --j)
            {
                matrix[j][n - 1 - i] = temp[j];
                //cout<<matrix[j][n - 1 - i]<<" ";
            }
            delete []temp;
            //cout<<endl;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix{vector<int>{5,1,9,11}, vector<int>{2,4,8,10}, vector<int>{13,3,6,7}, vector<int>{15,14,12,16}};
    s.rotate(matrix);
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 0; j < 4; ++j)
        {
            cout<<matrix[i][j]<<" ";
        }
    }
}