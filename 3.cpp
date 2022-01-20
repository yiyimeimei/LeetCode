class Solution {
public:
//memset(b, true, sizeof(b));
    int lengthOfLongestSubstring(string s)
    {
        /* if(s == "")
            return 0;
        else
        {
            bool flag[200] = {false};
            int length = s.length();
            int opt[length];
            opt[0] = 1;
            flag[(int)s[0]] = true;
            for(int i = 1; i < length; ++i)
            {
                int index = (int)s[i];
                if(flag[index] == true)
                {
                    opt[i] = 1;
                    memset(flag, false, sizeof(flag));
                }
                else
                {
                    opt[i] = opt[i - 1] + 1;
                }
                flag[index] = true;
            }
            int result = opt[0];
            for(int i = 1; i < length; ++i)
            {
                if(opt[i] > result)
                {
                    result = opt[i];
                }
            }
            return result;
        } */
        //滑动窗口
        /* int start = 0, end = 0, maxlen = 0;
        bool map[256] = {false};
        map[(int)*(s+start)] = 1;
        while( *(s+end) != 0 )
        {
            maxlen = maxlen>(end-start+1)?maxlen:(end-start+1);
            ++end;
            while(map[(int)*(s+end)] )//将要加入的新元素与map内元素冲突
            {
                map[ (int)*(s+start) ] = 0;
                ++start;
            }
            map[(int)*(s+end)] = 1;
        }
        return maxlen; */
        int start = 0, end = 0, maxlen = 0;
        bool map[256] = {false};
        map[(int)s[start]] = true;
        while(s[end] != '\0')
        {
            int length = end - start + 1;
            maxlen = maxlen > length ? maxlen : length;
            end++;
            int idx = (int)s[end];
            while(map[idx])
            {
                map[(int)s[start]] = false;
                start++;
            }
            map[idx] = true;
        }
        return maxlen;
    }
};