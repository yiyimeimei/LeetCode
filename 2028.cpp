#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        //int sum = mean * (n + m);
        
        int sum1 = 0;//m个骰子的和
        int m = rolls.size();
        for(int i = 0; i < m; ++i)
            sum1 += rolls[i];
        int sum2 = mean * (n + m) - sum1;//n个骰子的和
        if(sum2 > n * 6 || sum2 < n)
        {
            vector<int> result;
            return result;
        }
        if(sum2 == n * 6)
        {
            vector<int> result(n, 6);
            return result;
        }
        int k = 1;
        for(; k <= 6; ++k)
        {
            if(sum2 % (k * n) == sum2)
            {
                break;
            }
        }
        int difference = n * k - sum2;
        vector<int> result1(n - difference, k);
        vector<int> result2(difference, k - 1);
        result1.insert(result1.end(), result2.begin(), result2.end());
        return result1;
    }
};
int main()
{
    Solution s;
    vector<int> a{6,3,4,3,5,3};
    vector<int> b = s.missingRolls(a, 1,6);
}