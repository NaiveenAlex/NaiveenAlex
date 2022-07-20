class Solution {
public:
    const int n = 3;
    const int N = n * n;
    bool solved = false;
    
    unordered_map<int, set<int>> rows;
    unordered_map<int, set<int>> cols;
    unordered_map<int, set<int>> box;
    
    int getBoxIdx(int row, int col)
    {
        return (row / n)  * (n) + col / n ;
    }
    
    bool canPlaceNumer(vector<vector<char>>& board, int num, int row, int col)
    {
        if( board[row][col] == '.' &&
            rows[row].find(num) == rows[row].end() &&
            cols[col].find(num) == cols[col].end() &&
            box[getBoxIdx(row, col)].find(num) == box[getBoxIdx(row, col)].end() )
            return true;

        return false;
    }
    
    void addNumber(vector<vector<char>>& board, int num, int row, int col)
    {
        rows[row].insert(num);
        cols[col].insert(num);
        box[getBoxIdx(row, col)].insert(num);
        board[row][col] = num + '0';
    }
    
    void removeNumber(vector<vector<char>>& board, int num, int row, int col)
    {
        board[row][col] = '.';
        box[getBoxIdx(row, col)].erase(num);
        cols[col].erase(num);
        rows[row].erase(num);
    }
    
    void solve(vector<vector<char>>& board, int row, int col)
    {
        if(row == N ) 
        {
            solved = true;
            return;
        }
        int nextrow, nextcol;
        if(col == N - 1)
        {
            nextcol = 0;
            nextrow = row + 1;
        }
        else
        {
            nextcol = col + 1;
            nextrow = row;
        }
        
        if(board[row][col] == '.')
        {
            for(int num = 1; num <= 9; ++num)
            {
                if(canPlaceNumer(board, num, row, col))
                {
                    addNumber(board, num, row, col);
                                        
                    solve(board, nextrow, nextcol);
                    if(!solved)
                    {
                        removeNumber(board, num, row, col);
                    }
                }
            }
        }
        else
        {
            solve(board, nextrow, nextcol);
        }
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j)
            {
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - 48;
                    rows[i].insert(num);
                    cols[j].insert(num);
                    box[getBoxIdx(i, j)].insert(num);
                }
            }
    
        solve(board, 0, 0);
        return;
        
        
    }
};
