class UnionFind 
{
public:
    UnionFind(int sz):root(sz), rank(sz)
    {
        for (int i = 0; i < sz; i++) 
        {
            root[i] = i;
            rank[i] = 1;
            ++numRoots;
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

    void unionSet(int x, int y) 
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) 
        {
            if (rank[rootX] > rank[rootY]) 
            {
                root[rootY] = rootX;
                --numRoots;
            } 
            else 
            if (rank[rootX] < rank[rootY]) 
            {
                root[rootX] = rootY;
                --numRoots;
            } 
            else 
            {
                root[rootY] = rootX;
                rank[rootX] += 1;
                --numRoots;
            }
        }
    }

    bool connected(int x, int y) 
    {
        return find(x) == find(y);
    }
    
    int getRootCount()
    {
        return numRoots;
    }

private:
    vector<int> root;
    vector<int> rank;
    int numRoots;
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        UnionFind uf = UnionFind(isConnected.size());
        
        for(int i = 0 ; i < isConnected.size(); ++i)
            for(int j = i; j < isConnected[i].size(); ++j)
            {
                if(i != j && isConnected[i][j] == 1)
                {
                    uf.unionSet(i, j);
                }
            }
        
        return uf.getRootCount();
    }
};
