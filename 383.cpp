class Solution {
public:

    bool canConstruct(string ransomNote, string magazine) {
        int len1 = ransomNote.length();
        int len2 = magazine.length();
        unordered_map<char, int> map;
        for(int i = 0; i < len2; ++i)
        {
            auto iter = map.find(magazine[i]);
            if(iter == map.end())
            {
                map.emplace(magazine[i], 1);
            }
            else
            {
                ++iter->second;
            }
        }
        for(int i = 0; i < len1; ++i)
        {
            auto iter = map.find(ransomNote[i]);
            if(iter == map.end())
            {
                return false;
            }
            else
            {
                if(iter->second == 0)
                {
                    return false;
                }
                else
                {
                    --iter->second;
                }
            }
        }
        return true;

    }
};