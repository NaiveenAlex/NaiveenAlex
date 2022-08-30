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

    void unionSet(int x, int y, long long timestamp) 
    {
        //cout << " union set " << timestamp << ":" << x  << " " << y << endl;
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) 
        {
            if (rank[rootX] > rank[rootY]) 
            {
                root[rootY] = rootX;
                --numRoots;
                if(((earliest.count(rootX) > 0) &&
                    (earliest[rootX] < timestamp)) ||
                    (earliest.count(rootX) == 0))
                    {
                        earliest[rootX] = timestamp;
                    }
                if(earliest.count(rootY) > 0)
                    earliest.erase(rootY);
            }
            else 
            if (rank[rootX] < rank[rootY]) 
            {
                root[rootX] = rootY;
                --numRoots;
                if(((earliest.count(rootY) > 0) &&
                    (earliest[rootY] < timestamp)) ||
                    (earliest.count(rootY) == 0))
                    {
                        earliest[rootY] = timestamp;
                    }
                if(earliest.count(rootX) > 0)
                    earliest.erase(rootX);
            } 
            else 
            {
                root[rootY] = rootX;
                rank[rootX] += 1;
                --numRoots;
                if(((earliest.count(rootX) > 0) &&
                    (earliest.count(rootX) < timestamp)) ||
                    (earliest.count(rootX) == 0))
                    {
                        earliest[rootX] = timestamp;
                    }
                if(earliest.count(rootY) > 0)
                    earliest.erase(rootY);
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
    
    long long getEarliestTimestamp()
    {
        if (numRoots == 1)
            return earliest.begin()->second;
        else
            return -1;
    }

private:
    vector<int> root;
    vector<int> rank;
    unordered_map<int, long long> earliest;
    int numRoots = 0;
};

//LC 1101
class Solution 
{
public:
    int earliestAcq(vector<vector<int>>& logs, int n) 
    {
        UnionFind uf = UnionFind(n);
        
        //Sort based on timestamps
        std::sort(logs.begin(), logs.end(), [](const std::vector<int>& a, const std::vector<int>& b) 
        {
            return a[0] < b[0];
        }
                 );

        for(int i = 0 ; i < logs.size(); ++i)
        {
            {
                uf.unionSet( logs[i][1], logs[i][2], logs[i][0]);
            }
        }
        
        return uf.getEarliestTimestamp();  
    }
};
