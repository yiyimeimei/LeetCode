//贪心，首先把所有k=0的people[i]按照h从小到大的顺序放进queue，然后对于其他的people[i]，按照k从小到大排序，k相同的则按照h从大到小排序，然后遍历剩下的people[i]，插入到第一个满足其k条件的位置即可。
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(vector<int> x, vector<int> y)
    {
        if(x[1] ==0 && y[1] == 0)
            return x[0] < y[0];
        if(x[1] == y[1])
            return x[0] > y[0];
        return x[1] < y[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> queue;
        int len = people.size();
        if(len == 0 || len == 1)
            return people;
        sort(people.begin(), people.end(), comp);
        int i = 0;
        for(; i < len && people[i][1] == 0; ++i)
        {
            queue.push_back(people[i]);
        }
        for(; i < len; ++i)
        {
            int sum = 0;
            int qLen = queue.size();
            int j = 0;
            for(; j < qLen; ++j)
            {
                if(queue[j][0] >= people[i][0])
                    ++sum;
                if(sum == people[i][1])
                    break;
            }
            queue.insert(queue.begin() + j + 1, people[i]);
        }
        return queue;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> people;
    people.push_back(vector<int>{1, 0});
    people.push_back(vector<int>{2, 0});
    s.reconstructQueue(people);
}