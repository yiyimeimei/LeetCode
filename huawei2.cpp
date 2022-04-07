#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    bool **depend = new bool *[n];
    vector<vector<int>> record;
    for (int i = 0; i < n; ++i)
    {
        depend[i] = new bool[n]();
    }
    char ch;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;
        vector<int> temp;
        for (int j = 0; j < t; ++j)
        {
            ch = getchar();
            int num;
            cin >> num;
            depend[i][num] = true;
            temp.push_back(num);
        }
        record.push_back(temp);
    }
    queue<int> q;
    for(int i = 0; i < n; ++i)
    {
        if(depend[m][i])
            q.push(i);
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        int len = record[x].size();
        for(int i = 0; i < len; ++i)
        {
            if(!depend[m][record[x][i]])
            {
                q.push(record[x][i]);
                depend[m][record[x][i]] = true;
            }
        }
    }
    if (depend[m][m])
    {
        cout << -1;
        return 0;
    }
    int i = 0;
    for (; i < n; ++i)
    {
        if (depend[m][i])
        {
            cout << i;
            ++i;
            break;
        }
    }
    for (; i < n; ++i)
    {
        if (depend[m][i])
        {
            cout << ',' << i;
        }
    }
    return 0;
}