class Solution
{
public:
    
    int num, m, n;
    
    void dfs(int i, int j, vector<vector<bool>>& visited, const vector<vector<char>>& grid)
    {

            
        //cout << " " << i << " " << j << endl;
        
        if(i < 0 || j < 0 || i == m || j == n ) return;
        //cout << " safe " << endl;  


        if(grid[i][j] == '0' || visited[i][j]) return ;

        if(!visited[i][j])
            visited[i][j] = true;
        
        dfs(i - 1,  j, visited, grid);
        dfs(i , j - 1, visited, grid);
        dfs(i + 1,  j, visited, grid);
        dfs(i , j + 1, visited, grid);
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    
        m = grid.size();
        n = grid[0].size();
        
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    //cout << " dfs " << endl;
                    dfs(i, j, visited, grid);
                    ++num;
                }
            }
        }
        
        return num;
    
    }    
        
};
