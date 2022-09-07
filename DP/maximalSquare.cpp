class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int max = 0;
        vector<vector<int>> memo (matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        
        for(int i = 1; i <= matrix.size() ; ++i)
            for(int j = 1; j <= matrix[0].size() ; ++j)
            {
                
                if(matrix[i - 1][j - 1] == '1')
                {
                    memo[i][j] = min(memo[i-1][j-1], min(memo[i-1][j],memo[i][j-1])) + 1 ;
                    if(max == 0) max = 1;
                }
                if(memo[i][j] > max)
                    max = memo[i][j];
            }
            
        return max * max;
    }
};
