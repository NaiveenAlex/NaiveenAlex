class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        
        vector<vector<int>> memo(text1.size() + 2, vector<int>(text2.size() + 2));
        
        for(int i = 1; i <= text1.size(); ++i)
        {
            for(int j = 1; j <= text2.size(); ++j)
            {
                if(text1[i-1] == text2[j-1])
                {
                    memo[i][j] = memo[i-1][j-1] + 1;
                }
                else
                {
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }
        return memo[text1.size()][text2.size()];
    }
};
