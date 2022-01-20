#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int length = stones.size();
        int counter[3] = {0};
        for(int i = 0; i < length; ++i)
        {
            stones[i] %= 3;
            counter[stones[i]]++;
        }
        if(counter[0] % 2 == 0)//0石子偶数
        {
            if(counter[1] > 0 && counter[1] <= counter[2])
                return true;
            else if(counter[2] > 0 && counter[2] <= counter[1])
                return true;
            else
                return false;
        }
        else//0石子奇数,Bob能像上面一样获胜，Alice就可以获胜
        {
            if(counter[2] > counter[1] + 2 || counter[1] > counter[2] + 2)
                return true;
            else
                return false;
        }
    }
};