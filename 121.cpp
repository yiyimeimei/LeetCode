class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        vector<int> nums;//存储第i天之前所有日子最低的price
        int len = prices.size();
        int minP = prices[0];
        for(int i = 1; i < len; ++i)
        {
            result = max(result, prices[i] - minP);
            minP = min(minP, prices[i]);
        }
        return result;
    }
};