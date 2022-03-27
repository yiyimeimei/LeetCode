//贪心 按照结束时间从小到大排序 这样可以选到最多的区间 李国强讲过类似的
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int len = intervals.size();
        /* for(int i = 0; i < len; ++i)
        {
            int min = intervals[i][1], minindex = i;
            for(int j = i + 1; j < len; ++j)
            {
                if(intervals[j][1] < min)
                {
                    min = intervals[j][1];
                    minindex = j;
                }
            }
            if(minindex != i)
            {
                vector<int> temp = intervals[i];
                intervals[i] = intervals[minindex];
                intervals[minindex] = temp;
            }
        } */
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v)
        {
            return u[1] < v[1];
        });
        
        int count = 1;
        int cursor = intervals[0][1];
        for(int i = 1; i < len; ++i)
        {
            if(intervals[i][0] >= cursor)
            {
                cursor = intervals[i][1];
                ++count;
            }
        }
        return len - count;
    }
};