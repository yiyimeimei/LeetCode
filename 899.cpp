class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1)//无法改变相对位置，全部轮换一遍然后找到字典序最大的
        {
            int len = s.length();
            map<string, int> m;
            for(int i = 0; i < len; ++i)
            {
                m[s] = 1;
                string temp = s.substr(1, len - 1) + s[0];
                s = temp;
            }
            return m.begin()->first;
        }
        else//可以排出任意的字符串，所以按照字典序把字母排一下就可以
        {
            map<char, int> m;
            int len = s.length();
            for(int i = 0; i < len; ++i)
            {
                if(m.count(s[i]) == 0)
                {
                    m[s[i]] = 1;
                }
                else
                {
                    ++m[s[i]];
                }
            }
            string result;
            for(auto iter = m.begin(); iter != m.end(); ++iter)
            {
                string temp(iter->second, iter->first);
                result += temp;
            }
            return result;
        }
    }
};