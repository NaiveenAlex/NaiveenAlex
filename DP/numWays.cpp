//LC276
/*
You are painting a fence of n posts with k different colors. You must paint the posts following these rules:
  - Every post must be painted exactly one color.
  - There cannot be three or more consecutive posts with the same color.
  - Given the two integers n and k, return the number of ways you can paint the fence.
*/
class Solution 
{
public:
    int numWays(int n, int k) 
    {
        int lastButTwo = k;
        int lastButOne = k * k;
        int result = 0;
        if(n >= 1) result = lastButTwo;
        if(n >= 2) result = lastButOne;
        for(int i = 3; i <= n; ++i)
        {
            result = (k - 1) * (lastButOne + lastButTwo);
            lastButTwo = lastButOne;
            lastButOne = result;
        }
        return result;
    }
};
