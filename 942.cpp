class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> perm;
        int len = s.length();
        int left = 0, right = len;
        for(int i = 0; i < len; ++i)
        {
            if(s[i] == 'I')
            {
                perm.push_back(left++);
            }
            else
            {
                perm.push_back(right--);
            }
        }
        perm.push_back(left);
        return perm;
    }
};