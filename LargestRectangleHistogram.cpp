class Solution 
{
public:
    
    	int _n;
    	int * _segmentTree = nullptr;
	int rangeMinimumIndexUtil(int* segmentTree, vector<int>& heights,
                                  int seg_start, int seg_end, 
	                          int start, int end, int index)
	{
		if(start <= seg_start && end >= seg_end)
        	{
            		//cout << "rmi1 " << start << "-" << end << " " << index << ":" << endl;
			return segmentTree[index];
        	}
		if(seg_end < start || seg_start > end)
			return -1;
			
		int middle = seg_start + (seg_end - seg_start) / 2;

		int left_idx  = rangeMinimumIndexUtil(segmentTree, heights, seg_start, middle, start, end, index*2 + 1  );
		int right_idx = rangeMinimumIndexUtil(segmentTree, heights, middle + 1, seg_end, start, end, index*2 + 2);
	       //cout << "rmi2 " << start << "-" << end << " " << index << ":" <<left_idx << " " << right_idx << endl;

		if (left_idx == -1)  return right_idx;
		if (right_idx == -1) return left_idx;

		return heights[left_idx] < heights[right_idx] ? left_idx : right_idx;
	    
	}

	int rangeMinimumIndex(int* segmentTree, vector<int>& heights, int n, 
						  int start, int end)
	{
		if(start < 0 || end > n - 1 || start > end)
			return -1;

		return rangeMinimumIndexUtil(segmentTree, heights, 0, n - 1, start, end, 0);
	}

	int segmentTreeCtorUtil(int* segmentTree, vector<int>& heights, 
					        int start, int end, int index)
	{
		if(start == end)
		{
			segmentTree[index] = start;
        		//cout << "ctor " << start << "-" << end << " " << index << ":" << segmentTree[index] <<"="<<heights[segmentTree[index]]<< endl;
			return start;
		}

		int middle = start + (end - start) / 2;
		
		int left_idx  = segmentTreeCtorUtil(segmentTree, heights, start, middle, index*2 + 1  );
		int right_idx = segmentTreeCtorUtil(segmentTree, heights, middle + 1, end, index*2 + 2);
		
		if(heights[left_idx] < heights[right_idx])
			segmentTree[index] = left_idx;
		else
			segmentTree[index] = right_idx;
		
	        //cout << "ctor " << start << "-" << end << " " << index << ":" << segmentTree[index] <<"="<<heights[segmentTree[index]]<< endl;
		return segmentTree[index];
	}

	void segmentTreeCtor(int* segmentTree, vector<int>& heights )
	{
		int n = heights.size();

		segmentTreeCtorUtil(segmentTree, heights, 0, n - 1, 0);
	}


    
    int largestRectangleAreaHelper(vector<int>& heights, int start, int end)
    {
        if(start > end)
            return 0;
        
        /*int min_idx = start;
        for(int i = start; i <= end; ++i)
        {
            if(heights[min_idx] > heights[i])
                min_idx = i;
        }*/
        
	int rmq_idx = rangeMinimumIndex(_segmentTree, heights, _n, start, end);
		
        //cout << " rmq " << rmq_idx << " min " << min_idx << endl;
        return max({heights[rmq_idx] * (end - start + 1),
                   largestRectangleAreaHelper(heights, start, rmq_idx - 1),
                   largestRectangleAreaHelper(heights, rmq_idx + 1, end)});
    }
    
    int largestRectangleArea(vector<int>& heights) 
    {
	//int* segmentTree ;
	_n = heights.size();
    	int n = heights.size();
    	int x = (int)(ceil(log2(n)));
    	int max_size = 2*(int)pow(2,x) - 1;

    	_segmentTree = new int[max_size];
    	segmentTreeCtor(_segmentTree, heights);   
    
	int result =  largestRectangleAreaHelper(heights, 0, heights.size() - 1);
        
		
		//if(_segmentTree)
		//	delete _segmentTree;
		
	return result;
    }

};
