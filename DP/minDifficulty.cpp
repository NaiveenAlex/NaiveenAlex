class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        int n = jobDifficulty.size();
        
        if(n < d) return -1;
        
        vector<vector<int>> minDiff (n, vector<int>(d + 1, INT_MAX));
        
        // Set base case, last row and col on DP table
        minDiff[n-1][d] = jobDifficulty[n - 1];

        //Fill last column/complete all pending jobs
        for (int i = n - 2; i >= 0; i--) 
        {
            minDiff[i][d] = max(minDiff[i+1][d], jobDifficulty[i]);
        }
        
        for(int day = d - 1; day > 0; --day)
            for(int i = day - 1; i < n - (d - day); i++)
            {
                int hardest = 0;
                for(int j = i; j < n - (d - day); j++)
                {
                    hardest = max(jobDifficulty[j], hardest);
                    minDiff[i][day] = min(minDiff[i][day], hardest + minDiff[j + 1][day + 1]);
                }
            }

        
        
        return minDiff[0][1] ;
    }
};
