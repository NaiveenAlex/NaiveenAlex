
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int right_max = 0;
        int left_idx = 0, right_idx = 0;
        int left_max_idx = 0, left_max = 0;
        
        vector<int> sum (height.size(), 0);
        
        for(int i = 0; i < height.size(); ++i)
        {
            right_max = height[i];
            left_idx = i - 1;
            right_idx = i;
            
            while( left_idx >= 0 && height[left_idx] < right_max)
            {
                --left_idx;
            }
            
            if(left_idx < 0) left_idx = 0;

            if(left_idx == 0)
            {
                //Find max till right_idx
                left_idx = left_max_idx;
            }
            
            //cout << " right : " << right_idx <<"-"<< height[right_idx]
            //     << " left : "  << left_idx  <<"-"<< height[left_idx]<< endl;

            int h = min(height[left_idx], height[right_idx]);
            int s = 0;

            for(int j = left_idx; j < right_idx; ++j)
            {
                if(height[j] < h)
                    sum[j] = h - height[j];
                //cout << " water@ " << j << " " << sum[j] << endl; 
            }

            if(right_max > left_max)
            {
                left_max = right_max;
                left_max_idx = i;
            }
        }
        
        int result = 0;
        for(int w : sum)
            result += w;
        
        return result;
    }
};
