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

    void unionSet(int x, int y, const string& s) 
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
        }
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
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        UnionFind uf = UnionFind(s.size());

        for(int i = 0 ; i < pairs.size(); ++i)
        {
            {
                uf.unionSet( pairs[i][0], pairs[i][1], s);
            }
        }

        unordered_map<int, std::priority_queue<char, std::vector<char>, std::greater<char> >> node_heap;
        
   	for(int i = 0; i < s.size(); ++i)
        {
            int root = uf.find(i);
            node_heap[root].push(s[i]);
        }
    
	string result = "";
	
	for(int index = 0; index < s.size(); ++index)
        {
            int root = uf.find(index);
            char val = node_heap[root].top();
            result += val;
            node_heap[root].pop();
	}
	    
	return result;
    }
};
