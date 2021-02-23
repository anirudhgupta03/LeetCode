class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int max_straightsum = INT_MIN, min_straightsum = INT_MAX;
        int temp_maxsum = 0, temp_minsum = 0, array_sum = 0;
        
        for(int i = 0; i < A.size(); i++){
            
            temp_minsum += A[i];
            temp_maxsum += A[i];
            
            max_straightsum = max(max_straightsum,temp_maxsum);
            min_straightsum = min(min_straightsum,temp_minsum);
            
            if(temp_maxsum < 0){
                temp_maxsum = 0;
            }
            if(temp_minsum > 0){
                temp_minsum = 0;
            }
            
            array_sum += A[i];
        }
        
        if(array_sum == min_straightsum){
            return max_straightsum;
        }
        return max(max_straightsum,array_sum-min_straightsum);
    }
};
