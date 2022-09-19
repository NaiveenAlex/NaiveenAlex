//LC 518
/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<int> dp (amount + 1, 0);
        dp [0] = 1;
        for(int coin : coins)
        {
            for(int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }        
        }
        
       return dp[amount]; 
    }
};
