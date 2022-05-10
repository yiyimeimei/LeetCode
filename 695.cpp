class Solution
{

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<bool> temp(n, false);
        vector<vector<bool>> visited(m, temp);
        int result = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] && !visited[i][j])
                {
                    int square = 0;
                    queue<pair<int, int>> q;
                    q.push(pair<int, int>(i, j));
                    visited[i][j] = true;
                    ++square;
                    while (!q.empty())
                    {
                        pair<int, int> cur = q.front();
                        cout << cur.first << " " << cur.second << endl;
                        q.pop();
                        for (int x = -1; x <= 1; x += 2)
                        {
                            if (cur.first + x < 0 || cur.first + x >= m)
                                continue;
                            if (grid[cur.first + x][cur.second] && !visited[cur.first + x][cur.second])
                            {
                                q.push(pair<int, int>(cur.first + x, cur.second));
                                ++square;
                                visited[cur.first + x][cur.second] = true;
                            }
                        }
                        for (int x = -1; x <= 1; x += 2)
                        {
                            if (cur.second + x < 0 || cur.second + x >= n)
                                continue;
                            if (grid[cur.first][cur.second + x] && !visited[cur.first][cur.second + x])
                            {
                                q.push(pair<int, int>(cur.first, cur.second + x));
                                ++square;
                                visited[cur.first][cur.second + x] = true;
                            }
                        }
                    }
                    if (square > result)
                        result = square;
                }
            }
        }
        return result;
    }
};