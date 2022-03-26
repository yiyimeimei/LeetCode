#include <iostream>
using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        for(int i = 5; i <= n; i += 5)
        {
            int counter = 0;
            int x = i;
            while(1)
            {
                if((x % 5) == 0)
                {
                    
                    ++counter;
                    x /= 5;
                }
                else
                {
                    break;
                }
            }
            cnt += counter;
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    s.trailingZeroes(10);
}