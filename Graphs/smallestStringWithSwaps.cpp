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
    
    void insertToHeap(int index, const string& s)
    {
        int root = find(index);
        node_heap[root].push(s[index]);
    }
    
    char popFromHeap(int index)
    {
        int root = find(index);
        char val = node_heap[root].top();
        node_heap[root].pop();
        return val;
    }
    

private:
    vector<int> root;
    vector<int> rank;
    unordered_map<int, std::priority_queue<char, std::vector<char>, std::greater<char> >> node_heap;
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

   		for(int i = 0; i < s.size(); ++i)
            uf.insertToHeap(i, s);

		string result = "";
		
		for(int i = 0; i < s.size(); ++i)
			result = result + uf.popFromHeap(i);
			
		return result;
    }
};
