class Solution
{
public:
    
    
    pair<string, double> Find(unordered_map<string, pair<string, double>>& nodeWeights, string node)
    {
        if(nodeWeights.count(node) == 0)
            nodeWeights[node] = pair<string, double>(node, 1.0);
        
        //if the root weight is correct , weight would be 1. so no exponentiation here.
        if(nodeWeights[node].first != node)
        {
            pair<string, double> root = Find(nodeWeights, nodeWeights[node].first);
            nodeWeights[node] = pair<string, double>(root.first,
                                                     root.second * nodeWeights[node].second);
        }
        
        return nodeWeights[node];
    }
    
    void Union(unordered_map<string, pair<string, double>>& nodeWeights, 
                string nodeA, string nodeB, double value)
    {
        
        pair<string, double> nodeARoot = Find(nodeWeights, nodeA);
        pair<string, double> nodeBRoot = Find(nodeWeights, nodeB);
        
        if(nodeARoot.first != nodeBRoot.first)
        {
            nodeWeights[nodeARoot.first] = pair<string, double>(nodeBRoot.first,
                                            value * nodeBRoot.second / nodeARoot.second);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, 
                                vector<double>& values, 
                                vector<vector<string>>& queries) 
    {
        unordered_map<string, pair<string, double>> nodeWeights;
        
        vector<double> results;
        
        for(int i = 0; i < equations.size(); ++i)
        {
            Union (nodeWeights,
                   equations[i][0],
                   equations[i][1],
                   values[i]) ;
        }
        
        for(int i = 0; i < queries.size(); ++i)
        {
            results.push_back(0);
            string nodeA = queries[i][0];
            string nodeB = queries[i][1];
            
            if(nodeWeights.count(nodeA) == 0 || nodeWeights.count(nodeB) == 0)
                results[i] = -1;
            
            else
            {
                pair<string, double> nodeARoot = Find(nodeWeights, nodeA);
                pair<string, double> nodeBRoot = Find(nodeWeights, nodeB);

                if(nodeARoot.first != nodeBRoot.first)
                    results[i] = -1;
                else
                    results[i] = nodeARoot.second / nodeBRoot.second;
            }
        }
    
        return results;
    }

};
