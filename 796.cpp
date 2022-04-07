class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s == goal)
            return true;
        int len = s.length();
        for(int i = 0; i < len; ++i)
        {
            string temp = s.substr(1, len - 1);
            temp += s[0];
            s = temp;
            if(s == goal)
                return true;
        }
        return false;
    }
};