class Solution {
public:
    bool winnerOfGame(string colors) {
        int length = colors.length();
        int a = 0, b = 0;
        int Alice = 0, Bob = 0;
        for(int i = 0; i < length; ++i)
        {
            if(colors[i] == 'A')
            {
                b = 0;
                ++a;
                if(a >= 3)
                {
                    ++Alice;
                }
            }
            else
            {
                a = 0;
                ++b;
                if(b >= 3)
                {
                    ++Bob;
                }
            }
        }
        if(Alice > Bob)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};