
//44. Wildcard Matching
class Solution {
public:
    //*? ?* *<> ?<> ab*?a ab?*?a 
    
    // aaaaba abba ababa
        
    
    bool isMatch(string s, string p) 
    {
        int sx = 0, sp = 0, star = -1, idx = -1;
        
        while(sx < s.size())
        {
            //cout << " " << sp << " " << sx << endl;
            if(sp < p.size() && (p[sp] == s[sx] || p[sp] == '?'))
            {
                ++sp;
                ++sx;
            }
            else if(sp < p.size() && p[sp] == '*')
            {
                star = sp;
                idx  = sx;
                ++sp;
                //++sx;
            }
            else if(idx == -1)
            {
                return false;
            }
            else
            {
                if(star == p.size()) return false;
                sx = idx + 1;
                sp = star + 1;
                idx = sx;
            }
        }
        
        if(sp < p.size())
            for(int i = sp ; i < p.size(); ++i)
                if(p[i] != '*') return false;
        
        return true;
    }
};
