//BFS求最短路径 + 一个简单的算法
class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        //BFS
        int n = patience.size();
        if(!n)
            return 0;
        deque<int> q;
        vector<int> dis(n, 2000000);
        bool * visited = new bool[n]();
        bool **map;
        map = new bool *[n];
        for(int i = 0; i < n; ++i)
        {
            map[i] = new bool[n]();
        }
        int len = edges.size();
        for(int i = 0; i < len; ++i)
        {
            map[edges[i][0]][edges[i][1]] = true;
            map[edges[i][1]][edges[i][0]] = true;
        }
        visited[0] = true;
        dis[0] = 0;
        q.push_back(0);
        while(!q.empty())
        {
            int cur = q.front();
            visited[cur] = true;
            for(int i = 0; i < n; ++i)
            {
                if(map[cur][i] && !visited[i])
                {
                    dis[i] = min(dis[i], dis[cur] + 1);
                    q.push_back(i);
                }
            }
            q.pop_front();
        }
        //算
        int maxTime = 0;
        //delete []map[0];
        for(int i = 1; i < n; ++i)
        {
            int distance = dis[i] * 2;
            if(distance > patience[i])
            {
                int times =  (distance - 1) / patience[i];
                maxTime = max(maxTime, patience[i] * times + distance + 1);
            }
            else
            {
                maxTime = max(maxTime, distance + 1);
            }
            //delete []map[i];
        }
        //delete []visited;
        //delete []map;
        //dis.clear();
        //dis.shrink_to_fit();
        return maxTime;


    }
};