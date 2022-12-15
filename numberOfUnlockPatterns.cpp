class Solution {
public:
    
    unordered_map<int, unordered_set<int>> _possiblePaths = 
    {
        {1, {2,5,4,6,8}},
        {2, {1,4,5,6,3,7,9}},
        {3, {2,5,6,4,8}},
        {4, {1,2,5,7,8,3,9}},
        {5, {1,2,3,4,6,7,8,9}},
        {6, {1,2,3,5,7,8,9}},
        {7, {2,4,5,8,6}},
        {8, {7,4,5,6,9,1,3}},
        {9, {8,5,6,4,2}}
    };
    unordered_map<int, unordered_map<int, int>> _bridges ;
 

    int _result = 0;
    
    int _m = 0, _n = 0;
    void possiblePaths(int index, unordered_set<int>& path, int& size)
    {
        
        
        if(size == _n)
        {
            /*cout << "       " ;
            for(auto p : path)
                cout << p << ", ";
            cout << endl;*/
            path.erase(index);
            --size;
            ++_result;
            return;
        }
        
        if(size >= _m)
            ++_result;
        
        
        for(int p = 1; p <= 9; ++p)
        {
            if(path.count(p) == 0)
            {
                if(_possiblePaths[index].count(p) > 0 ||
                  path.count(_bridges[index][p]) > 0)
                {
                    path.insert(p);
                    ++size;
                    possiblePaths(p, path, size);
                    path.erase(p);
                }
            }
        }
        path.erase(index);
        --size;
    }
    
    
    int numberOfPatterns(int m, int n) 
    {
        _m = m;
        _n = n;
        
        _bridges[1][3] = _bridges[3][1] = 2;
        _bridges[1][7] = _bridges[7][1] = 4;
        _bridges[3][9] = _bridges[9][3] = 6;
        _bridges[7][9] = _bridges[9][7] = 8;
        _bridges[1][9] = _bridges[9][1] = _bridges[2][8] = _bridges[8][2] = _bridges[3][7] = _bridges[7][3] =   _bridges[4][6] = _bridges[6][4] = 5;
        
        unordered_set<int> path = {};
        int firstSize = 1;
        for(int i = 1; i <= 9; ++i)
        {
            //cout << i << endl;
            firstSize = 1;
            path.insert(i);
            possiblePaths(i, path, firstSize);
            path.erase(i);
        }
        
        return _result;
    }
};
