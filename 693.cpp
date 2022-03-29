class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool zero = (n % 2);
        n /= 2;
        while(n > 0)
        {
            bool bit = n % 2;
            if(bit == zero)
                return false;
            else
                zero = bit;
            n /= 2;
        }
        return true;
    }
};