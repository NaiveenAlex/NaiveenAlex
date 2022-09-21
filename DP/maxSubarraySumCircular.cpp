//LC918. Maximum Sum Circular Subarray
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int curMax = nums[0];
        int curMin = nums[0];
        int best = nums[0];            //Largest increasing sum
        int worst = nums[0];           //Longest decreasing sum
        int sum = nums[0];             //Total sum

        for(int i = 1 ; i < nums.size(); ++i)
        {
            sum += nums[i];
            curMax = max(nums[i], curMax + nums[i]);
            best = max(curMax, best);
            
            curMin = min(nums[i], curMin + nums[i]);
            worst  = min(curMin, worst);
        }

        return sum == worst ? best : max(sum - worst, best);
    }
};
