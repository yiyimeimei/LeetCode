class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int length = s.length();
        int i = 0;
        while(i + k < length)
        {
            string temp = s.substr(i, k);
            result.push_back(temp);
            i += k;
        }
        string temp = s.substr(i, length - i);
        int m = k - length + i;
        for(int j = 0; j < m; ++j)
        {
            temp += fill;
        }
        result.push_back(temp);
        return result;
    }
};