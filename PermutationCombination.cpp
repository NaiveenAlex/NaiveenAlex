class Solution {
public:
    vector<vector<int>> solution;
    int _n, _k;
    
    void backtrack(int m, vector<int>& row)
    {
        if(row.size() == _k)
        {
            vector<int> result = row;
            solution.emplace_back(result);
            return;
        }
        
        for(int i = m ; i <= _n; ++i)
        {
            row.emplace_back(i);
            backtrack(i + 1, row);
            row.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) 
    {
        _n = n;
        _k = k;
        
        vector<int> row;
        
        backtrack(1, row);
        
        return solution;
        
    }
};

class Solution {
public:
    int _n;
    vector<vector<int>> solution;
    
    void backtrack(int n, vector<int>& nums)
    {
        if(n == _n)
        {
            vector<int> result = nums;
            solution.emplace_back(nums);
            return;
        }
        
        for(int i = n; i < _n; ++i)
        {
            swap(nums[n], nums[i]);
            backtrack(n + 1, nums);
            swap(nums[n], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        _n = nums.size();
        backtrack(0, nums);
        return solution;
    }
};

class Solution {
public:
    int _n, _open, _close;
    vector<string> _result;
    
    void backtrack(int n, string& row, int open, int close)
    {

        if(n == _n)
        {
            if(open == close)
            {
                _result.emplace_back(row);
            }
            return;
        }

        if(n < _n)
        {
            row.push_back('(');
            backtrack(n + 1, row, open + 1, close);
            row.pop_back();
        }
        if(close < open)
        {
            row.push_back(')');
            backtrack(n + 1, row, open, close + 1);
            row.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        _n = 2*n;
        string row;
        backtrack(0, row, 0, 0);
        
        return _result;
        
    }
};
