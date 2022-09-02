//LC1168
class UnionFind 
{
public:
    UnionFind(int sz):root(sz), rank(sz)
    {
        for (int i = 0; i < sz; i++) 
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) 
    {
        if (x == root[x]) 
        {
            return x;
        }
        return root[x] = find(root[x]);
    }

    bool unionSet(int x, int y) 
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) 
        {
            if (rank[rootX] > rank[rootY]) 
            {
                root[rootY] = rootX;
            } 
            else 
            if (rank[rootX] < rank[rootY]) 
            {
                root[rootX] = rootY;
            } 
            else 
            {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
            return true;
        }
        
        return false;
    }

    bool connected(int x, int y) 
    {
        return find(x) == find(y);
    }
    

private:
    vector<int> root;
    vector<int> rank;
    
};

class Solution 
{
public:

    
    
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) 
    {
        //Create a virtual node '0', connect all nodes to this node with node cost as edge.
        for(int i = 0; i < wells.size(); ++i)
            pipes.push_back({0, i + 1, wells[i]});
        
        UnionFind uf = UnionFind(n + 1);
        
        //Sort all edges based on weight
        sort(pipes.begin(), pipes.end(), [](const std::vector<int>& a, const std::vector<int>& b) { return a[2] < b[2]; } );
        
        int totalCost = 0;
        
        
        for(auto pipe : pipes)
        {
            if(uf.unionSet(pipe[0], pipe[1]))
            {
                totalCost += pipe[2];
            }
        }
        
        return totalCost;
        
    }
};
