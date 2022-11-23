class Solution {
public:
    
    bool canSplit(vector<int>& nums, int largest, int k)
    {
        int curSum = 0;
        int partitions = 1;
        for(int n : nums)
        {
            curSum += n;
            if(curSum > largest)
            {
                curSum = n;
                ++partitions;
            }
        }
        
        //cout << " l " << largest << " p " << partitions << endl;
        return partitions <= k;
    }
    
    int splitArray(vector<int>& nums, int k) 
    {
        int maxNum = INT_MIN;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > maxNum)
            {
                maxNum = nums[i];
            }
            
            sum += nums[i];
        }
        
        
        int l = maxNum, r = sum;
        int result = 0;
        while( l <= r)
        {
            int mid = (l + (r - l)/2);
            if(canSplit(nums, mid, k))
            {
                result = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return result;
    }
};
