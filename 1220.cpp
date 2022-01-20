class Solution {
public:
    int countVowelPermutation(int n) {
        int result;
        int c = 1e9 + 7;
        long letter1[5] = {1, 1, 1, 1, 1};//a e i o u
        long letter2[5];
        --n;
        while(n > 0)
        {
            letter2[0] = (letter1[1] + letter1[2] + letter1[4]) % c;
            letter2[1] = (letter1[0] + letter1[2]) % c;
            letter2[2] = (letter1[1] + letter1[3]) % c;
            letter2[3] = letter1[2] % c;
            letter2[4] = (letter1[2] + letter1[3]) % c;
            for(int i = 0; i < 5; ++i)
            {
                letter1[i] = letter2[i];
            }
            --n;
        }
        result = (letter1[0] + letter1[1] + letter1[2] + letter1[3] + letter1[4]) % c;
        return result;
    }
};