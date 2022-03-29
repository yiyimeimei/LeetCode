class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len1 = strs.size();
        unordered_map<string, vector<string>> map;
        for(int i = 0; i < len1; ++i)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            auto iter = map.find(key);
            if(iter == map.end())
            {
                map.emplace(key, vector<string>{strs[i]});
            }
            else
            {
                iter->second.push_back(strs[i]);
            }
        }
        vector<vector<string>> result;
        for(auto iter = map.begin(); iter != map.end(); ++iter)
        {
            result.push_back(iter->second);
        }
        return result;
    }
};