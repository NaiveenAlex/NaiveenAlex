
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        unordered_map<int, int> _index;
        
        stack<int> _stack;
        unordered_map<int, int> _nextLarger;
        vector<int>_result;
    
        for(auto n : nums2)
        {
            if(_stack.empty())
                _stack.push(n);
            else
            {
                int top = _stack.top();
                while(!_stack.empty() && n > top)
                {
                    _nextLarger[top] = n;
                    _stack.pop();
                    if(!_stack.empty())
                        top = _stack.top();   
                    
                }
                _stack.push(n);
            }
        }
        
        while(!_stack.empty())
        {
            _nextLarger[_stack.top()] = -1;
            _stack.pop();
        }
        
        for(auto n : nums1)
        {
            _result.emplace_back(_nextLarger[n]);
        }
        
        return _result;
    }
};
