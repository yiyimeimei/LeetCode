class Solution {
public:
    bool isValid(string s) {
        stack<char> zhan;
        int len = s.length();
        for(int i = 0; i < len; ++i)
        {
            switch (s[i])
            {
            case '(':
                zhan.push('(');
                break;
            case ')':
                if(zhan.empty() || zhan.top() != '(')
                    return false;
                zhan.pop();
                break;
            case '[':
                zhan.push('[');
                break;
            case ']':
                if(zhan.empty() || zhan.top() != '[')
                    return false;
                zhan.pop();
                break;
            case '{':
                zhan.push('{');
                break;
            case '}':
                if(zhan.empty() || zhan.top() != '{')
                    return false;
                zhan.pop();
                break;
            default:
                break;
            }
        }
        if(zhan.empty())
            return true;
        return false;
    }
};