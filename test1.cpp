#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string, int> p1, pair<string, int> p2)
{
    return p1.second > p2.second;
}
int main()
{
    vector<string> str{"he", "she", "he", "me", "he", "me"};
    unordered_map<string, int> map;
    int len = str.size();
    for (int i = 0; i < len; ++i)
    {
        auto iter = map.find(str[i]);
        if (iter == map.end())
        {
            map.emplace(str[i], 1);
        }
        else
        {
            ++iter->second;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        auto result = map.begin();
        int maxFrequence = result->second;
        for (auto iter = ++map.begin(); iter != map.end(); ++iter)
        {
            if (iter->second > maxFrequence)
            {
                result = iter;
                maxFrequence = iter->second;
            }
        }
    }
    cout << result->first;
    // sort(map.begin(), map.end(), comp);
    /* vector<pair<string, int>> vec;
    for(auto iter = map.begin(); iter != map.end(); ++iter)
    {
        pair<string, int>temp = *iter;
        vec.push_back(temp);
    } */
    // sort(vec.begin(), vec.end(), comp);
    // cout<<vec.begin()->first;
}

int newKey = hash(key);

array[newKey];