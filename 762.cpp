class Solution
{
private:
    bool flag[100] = {0};
    int bitCounter = 0;
    int result = 0;
    void statistics()
    {
        if (!flag[0])
        {
            flag[0] = true;
            counter++;
        }
        else
        {
            int i = 0;
            for (int i = 0; i < 100; ++i)
        }
    }
    bool isPrime(int n)
    {
        int stop = sqrt(n) + 1;
        if (n == 2)
        {
            ++result;
            return;
        }
        if (n % 2 == 0)
        {
            return;
        }
        for (int i = 3; i <= stop; i += 2)
        {
            if (n % i == 0)
            {
                return;
            }
        }
        ++result;
        return;
    }

public:
    int countPrimeSetBits(int left, int right)
    {
        bool flag[100] = {0};
        int n = left;
        int c = 0;
        while (n > 0)
        {
            if (n % 2)
            {
                flag[c] = true;
            }
            n /= 2;
            ++c;
        }
        for (int i = 0; i < c; ++i)
        {
            if (flag[i])
                counter++;
        }
        for (int i = left + 1; i <= right; ++i)
        {
        }
    }
};