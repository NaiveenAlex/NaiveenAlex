class Solution {
public:
    string result ;
    
    string longestPalindrome(string s)
    {
        int length = INT_MIN;
        if(s.size() <= 1) return s;
        
        int l = 0;
        
        for(int i = 0; i < s.size(); ++i)
        {
            int l1 = expandFromCenter(s, i, i);
            int l2 = expandFromCenter(s, i, i + 1);
            
            int len = max(l1, l2);
            
            if(len > length)
            {
                length = len;
                l = i - (len - 1)/2;
            }
            
        }

        return s.substr(l, length);
    }
    
    int expandFromCenter(string& s, int L, int R)
    {
        while(L >=0 && R < s.size() && R >= L && s[L] == s[R])
        {
            --L;
            ++R;
        }
        
        return (R - L - 1);
    }
};
