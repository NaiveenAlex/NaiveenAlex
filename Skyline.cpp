class Solution {
public:

    vector<vector<int>> mergeSkylines(vector<vector<int>>& left_skyline, vector<vector<int>>& right_skyline)
    {
        //cout << " merge " << left_skyline.size() << " " << right_skyline.size() << endl;
        int left_idx = 0, right_idx = 0;
        int prev_pos = 0, prev_height = 0, cur_pos = 0, cur_height = 0;
        int prev_left_height = 0, prev_right_height = 0;
        
        vector<vector<int>> answer;
        
        while(left_idx < left_skyline.size() && right_idx < right_skyline.size())
        {
            if(left_skyline[left_idx][0] < right_skyline[right_idx][0])
            {
                cur_pos = left_skyline[left_idx][0];
                cur_height = max(left_skyline[left_idx][1], prev_right_height);
                prev_left_height = left_skyline[left_idx][1];
                ++left_idx;
            }
            else
            if(left_skyline[left_idx][0] > right_skyline[right_idx][0])
            {
                cur_pos = right_skyline[right_idx][0];
                cur_height = max(right_skyline[right_idx][1], prev_left_height);
                prev_right_height = right_skyline[right_idx][1];                
                ++right_idx;
            }
            else
            {
                cur_pos = right_skyline[right_idx][0];
                cur_height = max(right_skyline[right_idx][1], left_skyline[left_idx][1]);
                prev_left_height  = left_skyline[left_idx][1];
                prev_right_height = right_skyline[right_idx][1];                    
                ++right_idx;
                ++left_idx;
            }
            
            if(answer.empty() || cur_height != answer.back()[1])
            {
                answer.push_back({cur_pos, cur_height});
            }
        }
        
        while(left_idx < left_skyline.size())
        {
            answer.push_back(left_skyline[left_idx++]);
        }
        
        while(right_idx < right_skyline.size())
        {
            answer.push_back(right_skyline[right_idx++]);
        }
        
        return answer;
    }
    
    vector<vector<int>> getSkylineHelper(vector<vector<int>>& buildings, int left_idx, int right_idx) 
    {
        
        if(left_idx == right_idx)
        {
            return {{buildings[left_idx][0], buildings[left_idx][2]}, {buildings[left_idx][1], 0}};
        }

        int middle_idx = left_idx + (right_idx - left_idx) / 2;
        
        vector<vector<int>> left_skyline  = getSkylineHelper( buildings, left_idx, middle_idx);
        vector<vector<int>> right_skyline = getSkylineHelper( buildings, middle_idx + 1, right_idx);
        
        return mergeSkylines(left_skyline, right_skyline);
        
    }
    
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) 
    {
        return getSkylineHelper(buildings, 0, buildings.size() - 1);
    }
};
