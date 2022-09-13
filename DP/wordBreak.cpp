class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.size();
        vector<bool> memo(n + 1, false);
        
        memo[0] = true;
        
        for(int i = 1; i <= n; ++i)
        {
            for(string word : wordDict)
            {
                int w = word.size();
                if((i - w >= 0)  && (memo[i - w] && s.compare(i - w, w, word) == 0))
                {
                    memo[i] = true;
                    break;
                }
            }
        }
        
        return memo[n];
    }
};
