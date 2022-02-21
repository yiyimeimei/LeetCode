class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        bool negative = false, overSize = false;
        long result = 0;
        int tempResult = 0;
        while(s[i] == ' ')
        {
            ++i;
        }
        if(s[i] == '-')
        {
            negative = true;
            ++i;
        }
        else if(s[i] == '+')
        {
            ++i;
        }
        while(s[i] >= '0' && s[i] <= '9')
        {
            
            result *= 10;
            result += s[i] - '0';
            if(negative && result > 2147483648)
            {
                overSize = true;
                result = -2147483648;
                break;
            }
            else if(!negative && result > 2147483647)
            {
               overSize = true;
                result = 2147483647;
                break; 
            }
            ++i;
        }
        if(overSize)
        {
            return (int)result;
        }
        else
        {
            if(negative)
                result *= -1;
        }
        return result;

    }
};