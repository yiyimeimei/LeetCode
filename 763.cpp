#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int len = s.length();
        vector<vector<int>> location(26);
        for(int i = 0; i < len; ++i)
        {
            location[(int)(s[i] - 'a')].push_back(i);
        }
        vector<vector<int>> interval;
        for(int i = 0; i <= 25; ++i)
        {
            if(location[i].size() > 0)
            {
                interval.push_back(vector<int>{location[i][0], location[i][location[i].size() - 1]});
            }
        }
        sort(interval.begin(), interval.end(), comp);
       /*  for(int i = 0; i < interval.size(); ++i)
        {
            cout<<interval[i][0]<<" "<<interval[i][1]<<endl;
        }
         */
        vector<vector<int>> result;
        result.push_back(interval[0]);
        int len2 = interval.size();
        for(int i = 1; i < len2; ++i)
        {
            vector<int> temp = result[result.size() - 1];
            if(temp[1] > interval[i][0] && temp[1] < interval[i][1])
            {
                temp[1] = interval[i][1];
                result[result.size() - 1] = temp;
            }
            else if(temp[1] < interval[i][0])
            {
                result.push_back(interval[i]);
            }
        }
        int len3 = result.size();
        vector<int> count;
        for(int i = 0; i < len3; ++i)
        {
            count.push_back(result[i][1] - result[i][0] + 1);
        }
        return count;
    }
    static bool comp(vector<int> u, vector<int> v)
    {
        return u[0] < v[0];
    }
};

int main()
{
    Solution s;
    vector<int> r = s.partitionLabels("qvmwtmzzse");
    cout<<r[0]<<" "<<r[1];
}