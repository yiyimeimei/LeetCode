#include <iostream>
#include <math.h>
using namespace std;

/* class Solution {
public:
double Pow(int x, int n)
{
    int base = x;
    double result = 1;
    int y;
    if (n == 0)
        return 1;
    else if(n < 0)
        y = -n;
    else
        y = n;    

    while (y != 0)
    {
        //二进制的某一位是1，则乘以现在的base
        if (y & 1)
            result *= base;
        //base平方
        base *= base;
        //将指数右移1位
        y >>= 1;
    }
    if(n > 0)
        return result;
    else
        return double(1.0/result);
}
int Bit(int x)
{
    int bit = 0;
    int temp = x;
    while(temp != 0)
    {
        temp /= 10;
        ++bit;
    }
    return bit;
}
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x == 0)
            return true;
        else
        {
            bool flag = true;
            while(x > 0)
            {
                int bit = this->Bit(x);
                int last = x % 10;
                int first = x / (int)this->Pow(10, bit - 1);
                cout<<first<<"  "<<last<<endl;
                if(first != last)
                {
                    flag = false;
                    break;
                }
                x %= (int)this->Pow(10, bit - 1);
                x /= 10;
                cout<<"x"<<x<<endl;
            }
            return flag;
        }
    }
}; */


class Solution {
public:
int Bit(int x)
{
    int bit = 0;
    int temp = x;
    while(temp != 0)
    {
        temp /= 10;
        ++bit;
    }
    return bit;
}
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x == 0)
            return true;
        else
        {
            bool flag = true;
            int bit = this->Bit(x);
            int ch[20];
            for(int i = bit; i >= 1; --i)
            {
                ch[i] = x % 10;
                x /= 10;
            }
            int i = 1;
            int j = bit;
            while(i <= j)
            {
                if(ch[i] != ch[j])
                {
                    flag = false;
                    break;
                }
                ++i;
                --j;
            }
            return flag;
        }
    }
};
int main()
{
    int x = 11111;
    Solution s;
    cout<<s.isPalindrome(x);
}