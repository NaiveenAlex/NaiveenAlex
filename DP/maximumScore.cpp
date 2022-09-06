//LC 1770
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) 
    {
        int total = 0;
        
        int m = multipliers.size();
        int n = nums.size();
        vector<vector<int>> memo(m + 1, vector<int>(m + 1));
        
        for(int i = m - 1; i >= 0; --i)
        {
            for(int left = i; left >= 0; --left)
            {
                int right = n - 1 + left - i;
                int mult  = multipliers[i];
                memo[i][left] = max( mult * nums[left] + memo[i + 1][left + 1] , 
                                     mult * nums[right] + memo[i + 1][left]); 
            }
        }
        return memo[0][0];
    }
};
