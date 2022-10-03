//LC265. Paint House II

class Solution {
public:
    int minCostII(vector<vector<int>>& matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int result = INT_MAX;
        int min1 = INT_MAX, min2 = INT_MAX, minidx;
        
        for(int j = 0; j < n; ++j)
        {
            if(matrix[0][j] < min1)
            {
                min2 = min1;
                min1 = matrix[0][j];
                minidx = j;
            }
            else if(matrix[0][j] < min2)
            {
                min2 = matrix[0][j];
            }
        }
        
        if(m == 1) return min1;

        //cout << min2 << " " << min1 << endl;
         //   cout << minidx << ":" << min1 << " " << ":" << min2 << endl;
        
        int prev_min1 = min1;
        int prev_min2 = min2;
        int prev_minidx = minidx;

        
        for(int i = 1; i < m; ++i)
        {
            min1 = INT_MAX, min2 = INT_MAX;
            
            for(int j = 0; j < n; ++j)
            {
                int cost = matrix[i][j];
                if(j != prev_minidx)
                    cost += prev_min1;
                else
                    cost += prev_min2;
                if(cost < min1)
                {
                    min2 = min1;
                    min1 = cost;
                    minidx = j;
                }
                else if(cost < min2)
                {
                    min2 = cost;
                }
            }
                                        
           // cout << minidx << ":" << min1 <<  ":" << min2 << endl;
            
            prev_min1 = min1;
            prev_min2 = min2;
            prev_minidx = minidx;
                        
        }

        
        return prev_min1;        
    }    
};
