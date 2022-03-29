
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> word;
        int len = s.length();
        int start = 0, end = 0;
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        while(end < len)
        {
            if(s[end] != ' ')
            {
                ++end;
            }
            else
            {
                word.push_back(s.substr(start, end - start));
                start = end + 1;
                ++end;
            }
        }
        word.push_back(s.substr(start, end - start));
        int len1 = word.size();
        int len2 = pattern.length();
        if(len1 != len2)
            return false;
        for(int i = 0; i < len2; ++i)
        {
            auto iter1 = map1.find(pattern[i]);
            auto iter2 = map2.find(word[i]);
            if(iter1 == map1.end() && iter2 == map2.end())
            {
                map1.emplace(pattern[i], word[i]);
                map2.emplace(word[i], pattern[i]);
            }
            else if(iter1 != map1.end() && iter2 != map2.end())
            {
                if(iter1->second != word[i] || iter2->second != pattern[i])
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};
