class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        unordered_map<char, int> map;
        for(int i = 0; i < len1; ++i)
        {
            auto iter = map.find(s[i]);
            if(iter == map.end())
            {
                map.emplace(s[i], 1);
            }
            else
            {
                ++iter->second;
            }
        }
        for(int i = 0; i < len2; ++i)
        {
            auto iter = map.find(t[i]);
            if(iter == map.end())
            {
                return false;
            }
            else
            {
                --iter->second;
            }
        }
        for(auto iter = map.begin(); iter != map.end(); ++iter)
        {
            if(iter->second != 0)
            {
                return false;
            }
        }
        return true;
    }
};