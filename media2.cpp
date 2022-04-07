class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param prices double浮点型vector 
     * @return double浮点型
     */
    double maxProfit(vector<double>& prices) {
        vector<double> minPrice;
        double maxIncome = 0;
        minPrice.push_back(prices[0]);
        int len = prices.size();
        for(int i = 1; i < len; ++i)
        {
            maxIncome = max(maxIncome, prices[i] - minPrice[i - 1]);
            minPrice.push_back(min(minPrice[i - 1], prices[i]));
        }
        return maxIncome;
    }
};