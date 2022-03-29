#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if(num1 == "0" || num2 == "0")
            return "0";
        int len1 = num1.length(), len2 = num2.length();
        vector<int> digit1(len1), digit2(len2), digit3(len1 + len2);
        /* int *digit1, *digit2, *digit3;
        digit1 = new int[len1];
        digit2 = new int[len2];
        digit3 = new int[len1 + len2](); */
        for (int i = len1 - 1; i >= 0; --i)
        {
            digit1[len1 - 1 - i] = (int)(num1[i] - '0');
        }
        for (int i = len2 - 1; i >= 0; --i)
        {
            digit2[len2 - 1 - i] = (int)(num2[i] - '0');
        }
        int carry = 0;
        for (int i = 0; i < len1 - 1; ++i)
        {
            carry = 0;
            vector<int> digit4(len1 + len2);
            int p4 = i;
            for (int j = 0; j < len2; ++j)
            {
                int product = digit1[i] * digit2[j] + carry;
                carry = product / 10;
                digit4[p4++] = product % 10;
            }
            digit4[p4] = carry;
            carry = 0;
            for (int k = 0; k <= p4; ++k)
            {
                int sum = digit3[k] + digit4[k] + carry;
                carry = sum / 10;
                digit3[k] = sum % 10;
            }
            ++p4;
            while (carry != 0)
            {
                int sum = digit3[p4] + carry;
                carry = sum / 10;
                digit3[p4++] = sum % 10;
            }
        }
        carry = 0;
        vector<int> digit4(len1 + len2);
        int p4 = len1 - 1;
        for (int j = 0; j < len2; ++j)
        {
            int product = digit1[len1 - 1] * digit2[j] + carry;
            carry = product / 10;
            digit4[p4++] = product % 10;
        }
        digit4[p4] = carry;
        carry = 0;
        for (int k = 0; k <= p4; ++k)
        {
            int sum = digit3[k] + digit4[k] + carry;
            carry = sum / 10;
            digit3[k] = sum % 10;
        }
        ++p4;
        while (carry != 0)
        {
            int sum = digit3[p4] + carry;
            carry = sum / 10;
            digit3[p4++] = sum % 10;
        }
        --p4;
        while(digit3[p4] == 0 )
        {
            --p4;
        }
        string s = "";
        for (int i = p4; i >= 0; --i)
        {
            s += (char)(digit3[i] + 48);
        }
        return s;
    }
};
int main()
{
    Solution so;
    cout << so.multiply("9", "9");
}