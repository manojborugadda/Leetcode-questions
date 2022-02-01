class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int min_so_far = prices[0];
        int maxprofit = 0;
        for(int i=0;i<prices.size();i++)
        {
           min_so_far = min(min_so_far,prices[i]);
            int profit = prices[i]-min_so_far;
            maxprofit = max(maxprofit,profit);
        }
        return maxprofit;
    }
};