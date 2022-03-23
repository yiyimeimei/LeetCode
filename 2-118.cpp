class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int length = edges.size();
        bool *flag = new bool[length + 1]();
        vector<int> result;
        for(int i = 0; i < length; ++i)
        {
            if(flag[edges[i][0]] && flag[edges[i][1]])
            {
                result.push_back(edges[i][0]);
                result.push_back(edges[i][1]);
                break;
            }
            else
            {
                flag[edges[i][0]] = true;
                flag[edges[i][1]] = true;
            }
        }
        return result;
    }
};