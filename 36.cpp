class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        //判断横
        for(int i = 0; i < 9; ++i)
        {
            bool flag[10] = {0};
            for(int j = 0; j < 9; ++j)
            {
                if(board[i][j] == '.')
                    continue;
                int num = (int)board[i][j] - 48;
                if(flag[num])
                {
                    return false;
                }
                else
                {
                    flag[num] = true;
                }
            }
        }
        //判断竖
        for(int i = 0; i < 9; ++i)
        {
            bool flag[10] = {0};
            for(int j = 0; j < 9; ++j)
            {
                if(board[j][i] == '.')
                    continue;
                int num = (int)board[j][i] - 48;
                if(flag[num])
                {
                    return false;
                }
                else
                {
                    flag[num] = true;
                }
            }
        }
        //判断九宫格
        for(int i = 0; i < 9; i += 3)
        {
            for(int j = 0; j < 9; j += 3)
            {
                if(!helper(board, i, j))
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>& board, int x, int y)
    {
        bool flag[10] = {0};
        for(int i = x; i < x + 3; ++i)
        {
            for(int j = y; j < y + 3; ++j)
            {
                if(board[i][j] == '.')
                    continue;
                int num = (int)board[i][j] - 48;
                if(flag[num])
                {
                    return false;
                }
                else
                {
                    flag[num] = true;
                }
            }
        }
        return true;
    }
};