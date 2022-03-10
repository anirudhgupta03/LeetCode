class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        int minOp = 0;
        
        minOp = target[0];
        int prev = target[0];
        
        for(int i = 1; i < target.size(); i++){
            if(target[i] > prev){
                minOp += target[i] - prev;
            }
            prev = target[i];
        }
        return minOp;
    }
};
