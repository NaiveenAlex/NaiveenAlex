class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int total = 0, cost1 = 0, cost2 = 0;
        
        if(cost.size() > 1)
        {
            for(int i = 2; i <= cost.size(); ++i)
            {
                total = min(cost[i-1] + cost1, cost[i-2] + cost2);
                cost2 = cost1;
                cost1 = total;
            }
        }
        return total;
    }
};
