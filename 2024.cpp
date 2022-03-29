#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int len = answerKey.length();
        int t = 0, f = 0, l = 0, r = 1;
        bool cur;
        int result = 0;
        if(answerKey[0] == 'T')
        {
            cur = 1;
            ++t;
        }
        else
        {
            cur = 0;
            ++f;
        }
        while(r < len)//FFFTTFTTFT
        {
            if(answerKey[r] == 'T')
            {
                if(cur)
                {
                    ++t;
                    ++r;
                }
                else
                {
                    if(t < k)//可以修改
                    {
                        ++t;
                        ++r;
                    }
                    else//不能改了
                    {
                        result = max(result, t + f);
                        if(f <= t)
                        {
                            cur = true;
                        }
                        else
                        {
                            if(answerKey[l] == 'T')
                                --t;
                            else
                                --f;
                            ++l;
                        }
                    }
                }
            }
            else
            {
                if(!cur)
                {
                    ++f;
                    ++r;
                }
                else
                {
                    if(f < k)//可以修改
                    {
                        ++f;
                        ++r;
                    }
                    else//不能改了
                    {
                        result = max(result, t + f);
                        if(t <= f)
                        {
                            cur = false;
                        }
                        else
                        {
                            if(answerKey[l] == 'T')
                                --t;
                            else
                                --f;
                            ++l;
                        }
                    }
                }
            }
        }
        result = max(result, t + f);
        return result;
    }
};

int main()
{
    Solution s;
    cout<<s.maxConsecutiveAnswers("FFFTTFTTFT", 3);
}