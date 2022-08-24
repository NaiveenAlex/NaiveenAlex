class Solution {
public:
    unordered_map<int, int> memo;
    int rob(vector<int>& nums) 
    {
        if(nums.size() >= 1 ) 
            memo[0] = nums[0];
        
        if(nums.size() > 1)
        {
            memo[1] = max(nums[1], memo[0]);
            for(int i = 2; i < nums.size(); ++i)
                memo[i] = max(memo[i-1], nums[i] + memo[i-2]);
        }
        return memo[nums.size() - 1];
    }
};
