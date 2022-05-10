class Solution {
private:
    static bool comp(pair<string, string> &p1, pair<string, string> &p2)
    {
        if(p1.second != p2.second)
        {
            return p1.second < p2.second;
        }
        else
        {
            return p1.first < p2.first;
        }
        /* int m = p1.second < p2.second;
        if(m == 0)
        {
            int n = p1.first < p2.first;
            if(n == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(m == 1)
        {
            return true;
        }
        else
        {
            return false;
        } */
        
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> numberLog;
        vector<pair<string, string>> wordLog;
        int len = logs.size();
        for(int i = 0; i < len; ++i)
        {
            string str = logs[i];
            int j = 0;
            while(str[j] != '\0')
            {
                if(str[j] == ' ')
                {
                    if(str[j + 1] <= '9' && str[j + 1] >= '0')
                    {
                        numberLog.push_back(str);
                        break;
                    }
                    else if(str[j + 1] <= 'z' && str[j + 1] >= 'a')
                    {
                        string s1 = str.substr(0,j);
                        string s2 = str.substr(j+1);
                        pair<string, string> temp(s1, s2);
                        wordLog.push_back(temp);
                        break;
                    }
                }
                ++j;
            }
        }
        int len1 = wordLog.size();
        int len2 = numberLog.size();
        for(int i = 0; i < len1; ++i)
        {
            cout<<wordLog[i].second<<endl;
        }
        sort(wordLog.begin(), wordLog.end(), comp);
        for(int i = 0; i < len1; ++i)
        {
            cout<<wordLog[i].second<<endl;
        }
        vector<string> result;
        
        for(int i = 0; i < len1; ++i)
        {
            result.push_back(wordLog[i].first + " " + wordLog[i].second);
        }
        for(int i = 0; i < len2; ++i)
        {
            result.push_back(numberLog[i]);
        }
        return result;
    }
};