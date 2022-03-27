class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        int len3 = max(len1, len2) + 1;
        int *digit1 = new int [len1];
        int *digit2 = new int [len2];
        int *digit3 = new int [len3];
        for(int i = 0; i < len1; ++i)
        {
            digit1[i] = num1[len1 - 1 - i] - '0';
        }
        for(int i = 0; i < len2; ++i)
        {
            digit2[i] = num2[len2 - 1 - i] - '0';
        }
        int p1 = 0, p2 = 0, p3 = 0;
        bool carry = false;
        while(p1 < len1 && p2 < len2)
        {
            int sum = digit1[p1] + digit2[p2];
            if(carry)
                ++sum;
            if(sum > 9)
            {
                carry = true;
                sum -= 10;
            }
            else
                carry = false;
            digit3[p3] = sum;
            ++p1;
            ++p2;
            ++p3;
        }
        while(p1 < len1)
        {
            if(carry)
                ++digit1[p1];
            if(digit1[p1] > 9)
            {
                carry = true;
                digit1[p1] -= 10;
            }
            else
                carry = false;
            digit3[p3] = digit1[p1];
            ++p1;
            ++p3;
        }
        while(p2 < len2)
        {
            if(carry)
                ++digit2[p2];
            if(digit2[p2] > 9)
            {
                carry = true;
                digit2[p2] -= 10;
            }
            else
                carry = false;
            digit3[p3] = digit2[p2];
            ++p2;
            ++p3;
        }
        if(carry)
        {
            digit3[p3++] = 1;
        }
        string result;
        for(int i = p3 - 1; i >= 0; --i)
        {
            result += (char)(digit3[i] + '0');
        }
        delete []digit1;
        delete []digit2;
        delete []digit3;
        return result;
    }
};  