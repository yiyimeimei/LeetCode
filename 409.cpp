class Solution {
public:
    int longestPalindrome(string s) {
        //unordered_map<char, int> map;
        int statistics[123] = {0}; 
        int len = s.length();
        for(int i = 0; i < len; ++i)
        {
            statistics[(int)s[i]]++;
        }
        int c = 0;
        bool single = false;
        for(int i = 65; i <= 90; ++i)
        {
            if(statistics[i] % 2 == 0)
                c += statistics[i];
            else
            {
                single = true;
                c += statistics[i] - 1;
            }
        }
        for(int i = 97; i <= 122; ++i)
        {
            if(statistics[i] % 2 == 0)
                c += statistics[i];
            else
            {
                single = true;
                c += statistics[i] - 1;
            }
        }
        if(single)
            ++c;
        return c;
    }
};