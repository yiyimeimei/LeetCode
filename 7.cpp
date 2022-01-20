#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        bool negative = false;
        int result = 0;
        if (x == 0)
        {
            return 0;
        }
        if (x < 0)
        {
            if(x == -2147483648)
                return 0;
            negative = true;
            x = -x;
        }
        //计算x的位数
        int bit = 0;
        int temp = x;
        while (temp != 0)
        {
            temp /= 10;
            ++bit;
        }
        temp = x;
        //取出x的每一位
        for (int i = bit; i >= 1; --i)
        {
            if(result > 214748364)
            {
                return 0;
            }
            result = result * 10 + temp % 10;
            temp /= 10;
        }
        if(negative)
            result *= -1;
        return result;
    }
};

int main()
{
    int x = -2147483648;
    Solution s;
    cout<<s.reverse(x);
}