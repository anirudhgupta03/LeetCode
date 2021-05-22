class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int> ones;
        
        for(int i = 0; i < boxes.size(); i++){
            if(boxes[i] == '1'){
                ones.push_back(i);
            }
        }
        
        vector<int> res;
        
        for(int i = 0; i < boxes.size(); i++){
            int op = 0;
            for(int j = 0; j < ones.size(); j++){
                op += abs(ones[j] - i);
            }
            res.push_back(op);
        }
        
        return res;
    }
};
