
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct word
{
    int counter;
    int titleSequence;
    int titleCounter;
    int textSequence;
    word(int a, int b, int c, int d) : counter(a), titleSequence(b), textSequence(c), titleCounter(d) {}
};
bool comp(pair<string, word> p1, pair<string, word> p2)
{
    if(p1.second.counter == p2.second.counter)
    {
        if(p1.second.titleCounter == p2.second.titleCounter)
        {
            if(p1.second.titleSequence == p2.second.titleSequence)
            {
                return p1.second.textSequence < p2.second.textSequence;
            }
            return p1.second.titleSequence < p2.second.titleSequence;
        }
        return p1.second.titleCounter > p2.second.titleCounter;
    }
    return p1.second.counter > p2.second.counter;
}
int main()
{
    int n, m;
    cin >> n >> m;
    m = m * 2;
    int title = 0, text = 0;
    map<string, word> mmap;
    bool odd = true;
    string s;
    getline(cin, s);
    s.clear();
    for (int i = 1; i <= m; ++i) //奇数i为标题 偶数i为正文
    {
        getline(cin, s);
        int start = 0, end = 0, len = s.length();
        while (end <= len)
        {
            if (s[end] == ' ' || s[end] == '\0')
            {
                string temp = s.substr(start, end - start);
                auto iter = mmap.find(temp);
                if (iter != mmap.end())
                {
                    if (odd)
                    {
                        iter->second.counter += 3;
                        ++iter->second.titleCounter;
                        if (iter->second.titleSequence == 100005)
                            iter->second.titleSequence = i;
                    }
                    else
                    {
                        ++iter->second.counter;
                        if (iter->second.textSequence == 100005)
                            iter->second.textSequence = i;
                    }
                }
                else
                {
                    if (odd)
                    {
                        word newWord(3, title++, 2147483647, 1);
                        mmap.emplace(pair<string, word>(temp, newWord));
                    }
                    else
                    {
                        word newWord(1, 2147483647, text++, 0);
                        mmap.emplace(pair<string, word>(temp, newWord));
                    }
                }
                start = end + 1;
            }
            ++end;
        }
        odd = !odd;
    }
    vector<pair<string, word>> vec(mmap.begin(), mmap.end());
    sort(vec.begin(), vec.end(), comp);
    auto iter = vec.begin();
    for(int i = 0; i < n - 1; ++i)
    {
        cout<<iter->first<<" ";
        ++iter;
    }
    cout<<iter->first;
    return 0;
}
