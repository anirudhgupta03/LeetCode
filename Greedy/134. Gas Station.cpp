class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int excess = 0, shortage = 0;
        
        int start = 0;
        
        int n = gas.size();
        
        for(int i = 0; i < n; i++){
            
            if(gas[i] + excess < cost[i]){
                start = (i + 1)%n;
                shortage += gas[i] + excess - cost[i];
                excess = 0;
            }
            else{
                excess += gas[i] - cost[i];
            }
        }
        
        if(excess + shortage >= 0){
            return start;
        }
        return -1;
    }
};
