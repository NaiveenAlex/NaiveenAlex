//LC91 Given a string s containing only digits, return the number of ways to decode it.

class Solution 
{
public:
    int numDecodings(string s) 
    {
        if(s[0] == '0')   return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == 0 ? 0 : 1;
        
        for(int i = 2; i < dp.size(); ++i)
        {
            if(s[i - 1] != '0')
                dp[i] = dp[i - 1];
            
            int twoDigit = stoi(s.substr(i - 2, 2));
            if(twoDigit >= 10 && twoDigit <= 26)
                dp[i] += dp[i - 2];
        }
        
        
        return dp[s.size()];
    }
};
