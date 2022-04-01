class Solution {
public:
    static bool comp(int x, int y)
    {
        return x < y;
    }
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        int len = arr.size();
        unordered_map<int, int> map1, map2;
        int positive = len;
        int zero = len;
        int i = 0;
        int zeroCnt = 0;
        for(; i < len; ++i)
        {
            if(arr[i] >= 0)
            {
                zero = i;
                break;
            }
            auto iter = map1.find(arr[i]);
            if(iter == map1.end())
            {
                map1.emplace(arr[i], 1);
            }
            else
            {
                ++iter->second;
            }
        }
        for(; i < len; ++i)
        {
            if(arr[i] > 0)
            {
                positive = i;
                break;
            }
            ++zeroCnt;
        }
        if(zeroCnt % 2 != 0)
            return false;
        for(; i < len; ++i)
        {
            auto iter = map2.find(arr[i]);
            if(iter == map2.end())
            {
                map2.emplace(arr[i], 1);
            }
            else
            {
                ++iter->second;
            }
        }
        for(int i = positive; i < len; ++i)
        {
            auto iter1 = map2.find(arr[i]);
            if(iter1->second == 0)
            {
                continue;
            }
            auto iter2 = map2.find(arr[i] * 2);
            if(iter2 == map2.end())
            {
                return false;
            }
            if(iter2->second == 0)
            {
                return false;
            }
            --iter1->second;
            --iter2->second;
        }
        for(int i = zero - 1; i >= 0; --i)
        {
            auto iter1 = map1.find(arr[i]);
            if(iter1->second == 0)
            {
                continue;
            }
            auto iter2 = map1.find(arr[i] * 2);
            if(iter2 == map1.end())
            {
                return false;
            }
            if(iter2->second == 0)
            {
                return false;
            }
            --iter1->second;
            --iter2->second;
        }
        return true;
    }
};