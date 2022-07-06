class Solution {
public:
    
    int result;
    int size;
    
    void printBoard(std::vector<std::vector<int>>& board)
    {
        cout << endl;
        for(int i = 0; i < size; ++i)
        {
            cout << endl;
            for(int j = 0; j < size; ++j)
                cout << board[i][j] << ",";
        }
    }
    
    void nQueensHelper( std::vector<std::vector<int>>& board, int row)
    {
        if(row == size)
            return;
        
        bool set = false;
        for(int j = 0; j < size; ++j)
        {
            bool col = false;
            for(int k = 0; k < row; k++)
            {
                if(board[k][j] == 1)
                {
                    col = true;
                    break;
                }

                if(0 <= (k - row + j)  && 
                   (k - row + j) < size &&
                   board[k][k - row + j] == 1)  // Previous diagonals
                {
                    col = true;
                    break;
                }
                if( 0 <= - k + j + row &&
                   - k + j + row < size &&
                   board[k][ - k + j + row] == 1)//Previous anti-diagonals
                {
                    col = true;
                    break;
                }
            }
            if(!col)
            {
                board[row][j] = 1;
                nQueensHelper(board, row + 1);
                board[row][j] = 0;
                set = true;
            }
        }
        
        if(row == size - 1 && set)
        {
            //printBoard(board);
            ++result;
        }
    }
    
    
    int totalNQueens(int n) 
    {    
        size = n;
        std::vector<std::vector<int>> board( n, std::vector<int>(n)); 
        nQueensHelper(board, 0);
        return result;
    }
};
