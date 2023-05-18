class Solution {
public:
    int _jumps = INT_MAX;
    int _n = 0;
    unordered_map<int, vector<int>> _map;
    vector<bool> _visited;
    
    
    int minJumps(vector<int>& arr)
    {
        _n = arr.size();
        _visited = vector<bool>(_n, false);
        
        for(int i = 0; i < _n; ++i)
        {
            _map[arr[i]].emplace_back(i);
        }

        _visited[0] = true;

        queue<int> cur;
        cur.push(0);
        int jumps = 0;
        
        while(cur.size() > 0)
        {
            queue<int> next;
            
            while(!cur.empty())
            {
                auto node = cur.front();
                
                //cout << " processing node : " << node << " " << arr[node] << " " << jumps << endl;
                if(node == _n - 1)
                    return jumps;
                
                for(auto child : _map[arr[node]])
                    if(!_visited[child])
                    {
                        _visited[child] = true;
                        next.push(child);
                    }
                
                _map.erase(arr[node]);
                
                if(node - 1 >= 0 && !_visited[node - 1])
                {
                    _visited[node - 1] = true;
                    next.push(node - 1);
                }
                
                if(node + 1 <= _n - 1 && !_visited[node + 1])
                {
                    _visited[node + 1] = true;
                    next.push(node + 1);
                }
                
                cur.pop();
            }
            
            cur = next;
            jumps++;
        }
        
        return -1;
    }
};
