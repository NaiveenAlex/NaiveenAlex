///LC63. Unique Paths in matrix with obstacles
class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        //Set first column
        for(int i = 0; i < m; ++i)
        {
            if(i > 0 && obstacleGrid[i - 1][0] == INT_MIN)
                obstacleGrid[i][0] = INT_MIN;
            else
            if(obstacleGrid[i][0] == 1) 
                obstacleGrid[i][0] = INT_MIN;
            else
                obstacleGrid[i][0] = 1;
        }

        //Set First Row
        for(int j = 1; j < n; ++j)
        {
            if(j > 0 && obstacleGrid[0][j - 1] == INT_MIN)
                obstacleGrid[0][j] = INT_MIN;
            else
            if(obstacleGrid[0][j] == 1) 
                obstacleGrid[0][j] = INT_MIN;
            else
                obstacleGrid[0][j] = 1;
        }
     
        //Mark inner obstacles
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                if(obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = INT_MIN;
        
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
            {
                if(obstacleGrid[i][j] != INT_MIN)
                {
                    obstacleGrid[i][j] += obstacleGrid[i - 1][j] == INT_MIN ? 0 : obstacleGrid[i - 1][j]; 
                    obstacleGrid[i][j] += obstacleGrid[i][j - 1] == INT_MIN ? 0 : obstacleGrid[i][j - 1]; 
                }
            }
                    
        
        return obstacleGrid[m - 1][n - 1] == INT_MIN ? 0 : obstacleGrid[m - 1][n - 1];
    }
};
