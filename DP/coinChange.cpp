class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount == 0) return 0;
        vector<int> dp(amount + 1, amount + 1);
        dp [0] = 0;
        
        for(int coin : coins)
        {
            for(int i = 1; i < dp.size(); ++i)
            {
                if(i >= coin)
                {
                    dp[i] = min(dp[i], dp[i -coin]+1);
                }
            }
        }
        return dp[amount] == amount + 1 ?  -1 : dp[amount];
    }
};
