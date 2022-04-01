//滑动窗口

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].length();
        int n = words.size();
        int len = s.length();
        unordered_map<string, int> map;
        for(int i = 0; i < n; ++i)
        {
            auto iter = map.find(words[i]);
            if(iter == map.end())
            {
                map.emplace(words[i], 1);
            }
            else
            {
                ++iter->second;
            }
        }
        int windowLength = wordLength * n;
        int ptr = 0;
        vector<int> result;
        while(ptr + windowLength <= len)
        {
            string temp = s.substr(ptr, windowLength);
            unordered_map<string, int> tempMap = map;
            bool flag = true;
            for(int i = 0; i < windowLength; i += wordLength)
            {
                string word = temp.substr(i, wordLength);
                auto iter = tempMap.find(word);
                if(iter == tempMap.end() || iter->second == 0)
                {
                    flag = false;
                    break;
                }
                else
                {
                    --iter->second;
                }
            }
            if(flag)
            {
                for(auto iter = tempMap.begin(); iter != tempMap.end(); ++iter)
                {
                    if(iter->second > 0)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(flag)
                result.push_back(ptr);
            ++ptr;
        }
        return result;
    }
};