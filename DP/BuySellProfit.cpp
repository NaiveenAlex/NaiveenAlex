class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        
        for(int i = n - 1; i >= 0; --i)
            for(int t = 1; t <= k; ++t)
                for(int h = 0; h < 2; h++)
                {
                    int noAction = dp[i+1][t][h];
                    int action;
                    if(h == 0) //buy stock
                    {
                        action = -prices[i] + dp[i+1][t][1];
                    }
                    else
                    if(h == 1) //holding, sell stock
                    {
                        action = prices[i] + dp[i+1][t-1][0];
                    }
                    
                    dp[i][t][h] = max(action, noAction);
                }
        
        return dp[0][k][0];
    }
};
