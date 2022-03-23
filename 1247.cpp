class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int length = s1.length();
        int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
        int result = 0;
        for(int i = 0; i < length; ++i)
        {
            if(s1[i] == s2[i])
            {
                continue;
            }
            if(s1[i] == 'x')
            {
                ++x1;
            }
            else
            {
                ++y1;
            }
        }
        result += (x1 / 2);
        x1 %= 2;
        result += (y1 / 2);
        y1 %= 2;
        if(x1 == 1 && y1 == 1)
        {
            result += 2;
            return result;
        }
        else if(x1 == 0 && y1 == 0)
        {
            return result;
        }
        else
        {
            return -1;
        }
    }
};