#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int p1 = 0, p2 = 0;
        int len1 = pushed.size(), len2 = popped.size();
        stack<int> s;
        while (p1 < len1 && p2 < len2)
        {
            while (!s.empty() && s.top() == popped[p2])
            {
                s.pop();
                ++p2;
            }
            s.push(pushed[p1++]);
        }
        if (p1 == len1)
        {
            while (!s.empty() && s.top() == popped[p2])
            {
                s.pop();
                ++p2;
            }
            if (s.empty() && p2 == len2)
                return true;
        }
        else if (p2 == len2 && s.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> pushed{1, 2, 3, 4, 5};
    vector<int> popped{4,5,3,2,1};
    cout<<s.validateStackSequences(pushed, popped);

}