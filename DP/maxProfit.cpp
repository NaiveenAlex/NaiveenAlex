//LC121. Best Time to Buy and Sell Stock

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int buy = INT_MAX;
        int profit = INT_MIN;
        
        for(int price : prices)
        {
            buy = min(price, buy);
            profit = max(profit, price - buy);
        }
     
        return profit == INT_MIN ? 0 : profit; 
    }
};
