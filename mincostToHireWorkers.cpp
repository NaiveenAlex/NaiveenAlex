class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) 
    {
        int size = quality.size() ; 
        
        
        vector<pair<double, double>> qualityMap;
        
        for(int i = 0; i < size; ++i)
            qualityMap.emplace_back(make_pair(quality[i], wage[i]));

        sort(qualityMap.begin(), qualityMap.end());
        
        double result = FLT_MAX;
        for(int i = 0; i < size; ++i)
        {
            //Calculate Wj = (Wi/Qi) *Qj
            double Q_i = quality[i];
            double W_i = wage[i];
            double W = 0;
            int _k = k;
    
            //priority_queue<double, vector<double>, greater<double>> _queue;
            //cout << Q_i << endl;
            
            for(auto kv : qualityMap)
            {
                double wj = ((W_i) * kv.first)/ Q_i;
                if(wj >= kv.second)
                {
                //cout << " _____ " << wj << " " << kv.second << endl;
                    W += wj;
                    --_k;
                }
                else
                {
                    continue;
                }
                if(_k == 0)
                    break;
            }

            if(_k == 0)
                if(W < result)
                    result = W;
            //cout << "  " << W << " " << endl;
        }
        
        return result;
    }
};
