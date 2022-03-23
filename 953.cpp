#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    unordered_map<char, int> map;//存字母表 0-25
    bool isAlienSorted(vector<string>& words, string order) {
        int length = order.length();
        for(int i = 0; i < length; ++i)
        {
            map.emplace(order[i], i);
        }
        length = words.size();
        for(int i = 0; i < length - 1; ++i)
        {
            if(!compare(words[i], words[i + 1]))
            {
                return false;
            }
        }
        return true;
    }
    bool compare(string str1, string str2)
    {
        int len1 = str1.length();
        int len2 = str2.length();
        int len = min(len1, len2);
        for(int i = 0; i < len; ++i)
        {
            int seq1 = map.find(str1[i])->second;
            int seq2 = map.find(str2[i])->second;
            if(seq1 < seq2)
            {
                return true;//符合字典序
            }
            else if(seq1 == seq2)
            {
                continue;//比较下一位
            }
            else
            {
                return false;
            }
        }
        if(len1 > len2)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    Solution s;
    vector<string> x;
    x.push_back("word");
    x.push_back("world");
    x.push_back("row");
    string letter = "hlabcdefgijkmnopqrstuvwxyz";
    cout<<s.isAlienSorted(x, letter);
}