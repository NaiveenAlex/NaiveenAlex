class UnionFind 
{
    public:
    UnionFind(int sz) : root(sz), rank(sz) 
    {
        for (int i = 0; i < sz; i++) 
        {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) 
    {
        while (x != root[x]) 
        {
            x = root[x];
        }
        return x;
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
    bool validTree(int n, vector<vector<int>>& edges) 
    {
        if(edges.size() != n - 1 ) return false;
        
        UnionFind uf = UnionFind(n);
        
        for(auto edge : edges)
        {
            if(uf.unionSet(edge[0], edge[1]) == false)
                return false;
        }
        
        return true;
        
    }
};
