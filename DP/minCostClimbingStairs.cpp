class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int total = 0, memo1 = 0, memo2 = 0;
        
        if(cost.size() > 1)
        {
            for(int i = 2; i <= cost.size(); ++i)
            {
                total = min(cost[i-1] + memo1, cost[i-2] + memo2);
                memo2 = memo1;
                memo1 = total;
            }
        }
        return total;
    }
};
