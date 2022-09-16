//LC 309
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int profit = 0;
        
        vector<int> DP(n + 2);
                 
        
        for(int i = n - 1; i >= 0; --i)  //but index
        {
            int action = 0;
            for(int j = i + 1; j <= n - 1; ++j) //sell index
            {
                action = max(prices[j] - prices[i] + DP[j + 2], action); //1 day cooldown
            }
            
            int noAction = DP[i+1];
            
            DP[i] = max(action, noAction);
        }
            
        return DP[0];
    }
};
