//931. Minimum Falling Path Sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int result = INT_MAX;

        for(int i = 1; i < m; ++i)
            for(int j = 0; j < n; ++j)
            {
                if(j == 0)
                {
                    matrix[i][j] += min(matrix[max(0, i - 1)][j], 
                                        matrix[max(0, i - 1)][min(n - 1, j + 1)]);    
                }
                else
                if(j == n - 1)
                {
                     matrix[i][j] += min(matrix[max(0, i - 1)][max(0, j - 1)], 
                                       matrix[max(0, i - 1)][j]);    
                }
                else
                {
                     matrix[i][j] += min(min(matrix[max(0, i - 1)][max(0, j - 1)], 
                                       matrix[max(0, i - 1)][j]), 
                                       matrix[max(0, i - 1)][min(n - 1, j + 1)]);                       
                }
                
                if(i == m - 1)
                    result = min(result, matrix[m - 1][j]);

            }
       
        if(m == 1)
            for(int i = 0; i < m ; ++i)
                    result = min(result, matrix[0][i]);

        
        return result;
    }
};
