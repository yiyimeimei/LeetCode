class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string result;
        int len = s.length();
        int ptr = 0;
        while(ptr < len)
        {
            result += s[ptr];
            ptr += 2*numRows - 2;
        }
        for(int i = 2; i < numRows; ++i)
        {
            bool flag = true;
            ptr = i - 1;
            while(ptr < len)
            {
                result += s[ptr];
                if(flag)
                    ptr += 2*(numRows - i);
                else
                    ptr += 2*(i - 1);
                flag = !flag;
            }
        }
        ptr = numRows - 1;
        while(ptr < len)
        {
            result += s[ptr];
            ptr += 2*numRows - 2;
        }
        return result;
    }
};