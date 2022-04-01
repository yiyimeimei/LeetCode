class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left; i <= right; ++i)
        {
            int x = i;
            bool flag = true;
            while(x > 0)
            {
                int div = x % 10;
                if(div == 0 || i % div != 0)
                {
                    flag = false;
                    break;
                }
                x /= 10;
            }
            if(flag)
                result.push_back(i);
        }
        return result;
    }
};