class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        int len = intervals.size();
        if(!len)
            return result;
        for(int i = 0; i < len - 1; ++i)
        {
            int min = intervals[i][0], minIdx = i;
            for(int j = i + 1; j < len; ++j)
            {
                if(intervals[j][0] < min)
                {
                    min = intervals[j][0];
                    minIdx = j;
                }
            }
            if(minIdx != i)
            {
                vector<int> temp = intervals[i];
                intervals[i] = intervals[minIdx];
                intervals[minIdx] = temp;
            }
        }
        result.push_back(intervals[0]);
        for(int i = 1; i < len; ++i)
        {
            vector<int> temp = result.back();
            if(temp[1] >= intervals[i][0])
            {
                result.pop_back();
                result.push_back(vector<int>{temp[0], max(temp[1], intervals[i][1])});
            }
            else
            {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};