//Ultimate Level DP
class Solution {
public:
    
    map<pair<int,int>,int> mem;
    
    int partition(int ind, vector<int> &jobDifficulty, int d){
    
        if(d == 1){
            return *max_element(jobDifficulty.begin()+ind,jobDifficulty.end());
        }
        
        if(mem.find({d,ind}) != mem.end()){
            return mem[{d,ind}];
        }
        
        int maxIdx = jobDifficulty.size() - d;
        int minimum = INT_MAX;
        
        for(int i = ind; i <= maxIdx; i++){
            
                int dayCost = *max_element(jobDifficulty.begin()+ind,jobDifficulty.begin()+i+1);
                
                minimum = min(minimum,dayCost + partition(i+1,jobDifficulty,d-1));
            
        }
        
        mem[{d,ind}] = minimum;
        
        return minimum;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        if(jobDifficulty.size() < d){
            return -1;
        }
        
        if(jobDifficulty.size() == d){
            
            int sum = 0;
            for(auto x: jobDifficulty){
                sum += x;
            }
            
            return sum;
        }
        
        return partition(0,jobDifficulty,d);
    }
};
