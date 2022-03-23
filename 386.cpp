class Solution {
public:
    vector<int> result;
    int max;
    vector<int> lexicalOrder(int n) {
        int currentNumber = 1;
        max = n;
        for(; currentNumber <= 9; ++currentNumber)
        {
            if(currentNumber > max)
            {
                break;
            }
            result.push_back(currentNumber);
            helper(currentNumber);
        }
        return result;
    }
    void helper(int cur)
    {
        for(int i = 0; i <= 9; ++i)
        {
            int newNumber = cur * 10 + i;
            if(newNumber > max)
            {
                return;
            }
            else
            {
                result.push_back(newNumber);
                helper(newNumber);
            }
        }
    }

};