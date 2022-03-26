#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        int len = s.length();
        for(int i = 0; i < len; ++i)
        {
            auto it = map.find(s[i]);
            if(it != map.end())
            {
                ++it->second;
            }
            else
            {
                map.emplace(s[i], 1);
            }
        }
        int minIndex = len;
        for(auto iter = map.begin(); iter != map.end(); ++iter)
        {
            //cout<<iter->first<<" "<<iter->second<<endl;
            if(iter->second == 1)
            {
                int idx = s.find(iter->first);
                if(idx < minIndex)
                    minIndex = idx;
            }
        }
        if(minIndex == len)
            minIndex = -1;
        return minIndex;
    }
};

int main()
{
    Solution s;
    cout<<s.firstUniqChar("leetcode");
}