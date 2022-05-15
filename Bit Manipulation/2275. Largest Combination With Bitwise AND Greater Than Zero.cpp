class Solution {
public:
    vector<int> findBits(int num){
        
        vector<int> v(32, 0);
        
        for(int i = 0; i <= 31; i++){
            v[i] = num % 2;
            num /= 2;
        }
        return v;
    }
    int largestCombination(vector<int>& candidates) {
        
        int n = candidates.size();
        
        vector<int> allbits(32, 0);
        
        for(int i = 0; i < candidates.size(); i++){
            vector<int> v = findBits(candidates[i]);
            for(int j = 0; j < 32; j++){
                allbits[j] += v[j];
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < 32; i++){
            count = max(count, allbits[i]);
        }
        return count;
    }
};
