class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size();
        int n = nums2.size();
        
        if(m > n)
            return findMedianSortedArrays(nums2, nums1);
        
        const int partition_size = (m + n + 1) / 2;
        
        int low = 0, high = m;
        
        bool even = (m + n)%2 == 0 ? true : false;
        while(low <= high)
        {
        
            int partition1 = (high + low) / 2;

            int partition2 = partition_size - partition1;

            int num_low1    = partition1 - 1 < 0 ? INT_MIN : nums1[partition1 - 1];        
            int num_high1   = partition1 == m    ? INT_MAX : nums1[partition1];
            int num_low2    = partition2 - 1 < 0 ? INT_MIN : nums2[partition2 - 1];
            int num_high2   = partition2 == n    ? INT_MAX : nums2[partition2];
            
            if(num_low1 <= num_high2 && num_low2 <= num_high1)
            {
                if(even)
                {
                    return (max(num_low1, num_low2) + min(num_high1, num_high2))/2.0;
                }
                else
                {
                    return max(num_low1, num_low2);                    
                }
            }
            else
            if(num_low1 > num_high2)
            {
                high = partition1 - 1;
            }
            else
            {
                low = partition1 + 1;
            }
        }
        
        return -1;
    }
};
