class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        int count = 0, temp = INT_MIN;;
        
        for(int i = 0; i < A.size(); i++){
            if(A[i] < 0){
                count++;
                temp = max(temp,A[i]);
            }
            A[i] = -1*A[i];
        }
        
        if(count == A.size()){
            return temp;
        }
        int currsum = 0, maxsum = INT_MIN, sum = 0;
        
        for(int i = 0; i < A.size(); i++){
            
            currsum += A[i];
            sum += A[i];
            
            maxsum = max(maxsum,currsum);
            
            if(currsum < 0){
                currsum = 0;
            }
        }
        
        int inversion_ans = -1*(sum - maxsum);
        
        for(int i = 0; i < A.size(); i++){
            A[i] = -1*A[i];
        }
        
        currsum = 0, maxsum = INT_MIN;
        
        for(int i = 0; i < A.size(); i++){
            
            currsum += A[i];
            sum += A[i];
            
            maxsum = max(maxsum,currsum);
            
            if(currsum < 0){
                currsum = 0;
            }
        }
        
        int kadane_ans = maxsum;
        
        return max(kadane_ans,inversion_ans);
    }
};
