//有点麻薯了。。。是连续子数组 我真的无语啊啊啊
//而且两层for会超时，真醉了。。。啊啊啊啊
/* class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            int sum = 0;
            for(int j = i; j < n; ++j)
            {
                sum += nums[j];
                if(sum == k)
                    count++;
            }
        }
        return count;
    }
}; */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> map;
        int sum = 0;
        map.emplace(0, 1);
        for(int i = 0; i < n; ++i)
        {
            sum += nums[i];
            auto iter2 = map.find(sum - k);
            if(iter2 != map.end())
            {
                count += iter2->second;
            }
            auto iter1 = map.find(sum);
            if(iter1 == map.end())
            {
                map.emplace(sum, 1);
            }
            else
            {
                ++iter1->second;
            }
        }
        return count;
    }
};