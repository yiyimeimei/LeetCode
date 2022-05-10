class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size();
        int n = image[0].size();
        vector<bool> temp(n, false);
        vector<vector<bool>> visited(m, temp);

        int color = image[sr][sc];
        queue<pair<int, int>> q;
        q.push(pair<int, int>(sr, sc));
        image[sr][sc] = newColor;
        while(!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            //image[cur.first][cur.second] = newColor;
            if(cur.first + 1 < m && image[cur.first + 1][cur.second] == color && !visited[cur.first + 1][cur.second])
            {
                q.push(pair<int, int>(cur.first + 1, cur.second));
                image[cur.first + 1][cur.second] = newColor;
                visited[cur.first + 1][cur.second] = true;
            }
            if(cur.first - 1 >= 0 && image[cur.first - 1][cur.second] == color && !visited[cur.first - 1][cur.second])
            {
                q.push(pair<int, int>(cur.first - 1, cur.second));
                image[cur.first - 1][cur.second] = newColor;
                visited[cur.first - 1][cur.second] = true;
            }
            if(cur.second + 1 < n && image[cur.first][cur.second + 1] == color && !visited[cur.first][cur.second + 1])
            {
                q.push(pair<int, int>(cur.first, cur.second + 1));
                image[cur.first][cur.second + 1] = newColor;
                visited[cur.first][cur.second + 1] = true;
            }
            if(cur.second - 1 >= 0 && image[cur.first][cur.second - 1] == color && !visited[cur.first][cur.second - 1])
            {
                q.push(pair<int, int>(cur.first, cur.second - 1));
                image[cur.first][cur.second - 1] = newColor;
                visited[cur.first][cur.second - 1] = true;
            }

        }
        return image;
    }
};