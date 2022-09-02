class Solution 
{
    public:
    int deleteAndEarn(vector<int>& nums)
    {
        unordered_map<int, int> points;
        int maxNum = 0;
        
        for(int i = 0; i < nums.size(); ++i)
        {
            if(points.count(nums[i]) == 0 )
            {
                points[nums[i]] = 1;
                if(nums[i] > maxNum) maxNum = nums[i];
            }
            else
                points[nums[i]] += 1;
        }
        int* maxPoints = new int[maxNum + 1];
        
        maxPoints[0] = 0;
        
        if(points.count(1) == 0)
            maxPoints[1] = 0;
        else
            maxPoints[1] = points[1];
        
        for(int i = 2; i <= maxNum; ++i)
            maxPoints[i] = max(maxPoints[i-1], maxPoints[i-2] + i*points[i]);
        
        return maxPoints[maxNum];
    }
};
